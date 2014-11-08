<?php
/*
API call example

<api>
   <authentication>
      <api_key>xxxxxxxxxxxx</api_key>
      <shared_secret>xxxxxxxxxxxx</shared_secret>
      <response_type>xml</response_type>
   </authentication>
   <data>
      <methodCall>
         <methodName>transactional.____________</methodName>
         ...
      </methodCall>
      <methodCall>
         <methodName>transactional.____________</methodName>
         ...
      </methodCall>
   </data>
</api>

*/

/*
Revisions:

11/6/2009 - added CDATA to data_url in manage
11/18/2009 - added addCustomField method
*/

define('DEBUG_EMAIL','');

class BF_Esp_Bluehornet
{

    private $debug = false;
    private $_logCalls = true;

    function __construct($auth)
    {



        $this->apiKey = $auth['apiKey'];
        $this->sharedSecret = $auth['sharedSecret'];
        $this->apiURL = "https://{$auth['apiDomain']}/api/xmlrpc/index.php";
        $this->responseType = 'php'; //will return an array
        //$this->no_halt = 1;
        $this->methodCount = 0;

        if($auth['cid']){
            $this->codehash = $auth['cid'];
        }

        if($auth['accessLevel']) {
            $this->accessLevel = $auth['accessLevel'];
        }

    }

    public function setResponseType($responseType)
    {
        $this->responseType = $responseType;
    }

    public function setOutputPostData()
    {
        $this->outputPostData = true;
    }

    public function setDebug($debug) {
        $this->debug = $debug;
    }

    public function setCodehash($codehash)
    {
      $this->codehash = $codehash;
    }

    private function hitServer($returnRaw = false)
    {
//error_reporting(E_ALL);
        if($this->buildTransaction){
            return false;
        }

/* raw XML POST, does not currently work
        //$vars .= 'data=' . urlencode($this->constructMessage());
    $xml_payload = $this->constructMessage();

        //Grab result using CURL
        $ch = curl_init();
        curl_setopt($ch, CURLOPT_URL, $this->apiURL);
        //curl_setopt($ch, CURLOPT_POST, true);
        curl_setopt($ch, CURLOPT_POSTFIELDS, $xml_payload);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($ch, CURLOPT_HTTPHEADER, array('Connection: close'));
*/
        $xml = $this->constructMessage();

        $vars = 'data=' . urlencode($xml);
        $startTime = time();

        if($this->debug) {
            echo "apiURL - {$this->apiURL}<br><br>\n";
            echo $xml."<br><br>\n";
        }

//echo urldecode($vars);
        //Grab result using CURL
        $ch = curl_init();
        curl_setopt($ch, CURLOPT_URL, $this->apiURL);
        curl_setopt($ch, CURLOPT_POST, true);
        curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false); // until BH has a cert for echo.bandfarm.com
        curl_setopt($ch, CURLOPT_POSTFIELDS, $vars);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);

        //Set timeout
        if($this->timeout)
        {
            curl_setopt($ch, CURLOPT_TIMEOUT, $this->timeout);
        }

        $output = curl_exec($ch);
        $endTime = time();
        if($this->debug) echo "output - $output<br>\n";
        $this->error  = curl_error($ch);
        if($this->debug) {
            echo "error: ".$this->error."<br>\n";
            exit;
        }

        curl_close($ch);

        if($returnRaw) {
            return $output;
        }

        if($this->_logCalls) {
            $data = array(  'requestTime'=>date('Y-m-d G:i:s',$startTime),
                            'duration'=>$endTime-$startTime,
                            'method'=>$this->methods[0],
                            'xml'=>$xml,
                            'response'=>$output,
                            'error'=>$this->error);
            $this->logCall($data);
        }

        if($output){
            if($this->responseType == 'php'){
                $output = trim($output);
                $response = unserialize($output);
                if($response[0]['error']) {
                    //throw new Exception($response[0]['responseText']);
                    mail(DEBUG_EMAIL,'API error '.$this->codehash,print_r($response,true)."\n".print_r($_SERVER, true).$vars,'from:BMApiError');
                }
            }else{
                //$dom = new DOMDocument();
                //if (!$dom->loadXML($output)) {
                //    return false;
                //}

                $response = $output;
            }

            return $response;
        }else{
            return false;
        }
    }

    private function logCall($data) {
        $insert['requestTime'] = $data['requestTime'];
        $insert['totaltime'] = 2.2;
        $insert['method'] = $data['method'];
        $insert['xml'] = $data['xml'];
        $insert['response'] = $data['response'];
        $insert['error'] = $data['error'];

        //$bhApiLog = new Zend_Db_Table('bhApiLog');
//Zend_Debug::dump($bhApiLog);
//Zend_Debug::dump($insert,'insert data');
        //$bhApiLog->insert($insert);
    }

    private function constructMessage()
    {

        $return = "
       <api>
           <authentication>
              <api_key>". $this->apiKey ."</api_key>
              <shared_secret>". $this->sharedSecret ."</shared_secret>
              <response_type>". $this->responseType ."</response_type>
              <no_halt>".$this->no_halt."</no_halt>
           </authentication>
           <data>
        ";

        foreach($this->methods as $method){

            if(!$method['data']) $method['data'] = array();

            $return .= "
            <methodCall>
                <methodName>{$method['methodName']}</methodName>";

      if(!$method['data']['codehash'] && $this->codehash){
        $method['data']['codehash'] = $this->codehash;
      }

            foreach($method['data'] as $key => $value){
                $return .= "
                <{$key}>{$value}</{$key}>";
            }

            $return .= "
            </methodCall>
            ";
        }

        $return .= "
            </data>
        </api>";

        // reset since all methods have been used
        $this->methods = array();

        if($this->outputPostData){
            echo $return . "\n\n";
        }

        return $return;

    }

    /*
     *
     * the following two transaction functions will allow the system to build a single API call with multiple methods
     *
     */
    public function startTransaction()
    {
        $this->buildTransaction = true;
    }

    public function commitTransaction()
    {

        $this->buildTransaction = false;
        $this->methodCount = 1;

        return $this->hitServer();
    }

    private function incrementMethodCount()
    {
        $this->methodCount++;
    }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // BF Application Methods
    public function getSubscriber2($email)
    {

        $this->setResponseType('xml');

        $XMLresponse = $this->searchSubscribers(array('email'=>$email,'extended'=>1));

        $responseData = $this->parseXMLResponse($XMLresponse);

        $contact = $this->xml2array($responseData);

        foreach($contact['contact_data'] as $key=>$value) {
            if(is_array($value) && count($value) == 0) {
                $data[$key] = '';
            }else{
                $data[$key] = $value;
            }
        }

        return $data;
    }


    public function updateSubscriber($data)
    {
        $this->setResponseType('php');
        $response = $this->addUpdateSubscriber($data);
        return $response[0]['responseData'];
    }



    //standard bh Methods
    public function checkCredentials()
    {
        $response = $this->searchSubscribers(array('limit'=>1));

        if($response[0]['error']) {
            if(strpos($response[0]['responseText'], 'authenticate')) {
                $responseText = 'Could not authenticate';
            } elseif(strpos($response[0]['responseText'], 'Request')) {
                $responseText = 'You must whitelist the following IP addresses: ';
            } else {
                $responseText = 'Unknown Error';
            }
            return array('error'=>true,'responseText'=>$responseText);
        }

        return true;
    }

    public function listActions()
    {
        $this->incrementMethodCount();

        $this->methods[]['methodName'] = 'api.listactions';

        return $this->hitServer();
    }

    public function addUpdateSubscriber($data)
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'legacy.manage_subscriber';

        $this->methods[$this->methodCount]['data'] = $data;

        $response = $this->hitServer();

        return $response[0]['responseData'];
    }

    public function unsubscribeSubscriber($data)
    {
        $this->incrementMethodCount();

    $this->methods[$this->methodCount]['methodName'] = 'legacy.manage_subscriber';

        $this->methods[$this->methodCount]['data'] = $data;

        return "method not complete";

    }


    // Account Methods
    public function addStaticSegment($name,$categoryID='')
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'account.addStaticSegment';

        $this->methods[$this->methodCount]['data']['name'] = $name;
        $this->methods[$this->methodCount]['data']['category_id'] = $categoryID;

        $response = $this->hitServer();
//Zend_Debug::dump($response);
        return $response[0]['responseData'];
    }

    public function getStaticSegments($limit=null,$offset=null)
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'account.getStaticSegments';

        $this->methods[$this->methodCount]['data']['limit'] = $limit;
        $this->methods[$this->methodCount]['data']['offset'] = $offset;

        $response = $this->hitServer();

        return $response[0];
    }

    public function removeStaticSegment($id)
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'account.removeStaticSegment';

        $this->methods[$this->methodCount]['data']['id'] = $id;

        $response = $this->hitServer();

        return $response[0];
    }

    public function getCustomFields($limit=null,$offset=null)
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'account.getCustomFields';

        $this->methods[$this->methodCount]['data']['limit'] = $limit;
        $this->methods[$this->methodCount]['data']['offset'] = $offset;

        $response = $this->hitServer();



        return $response[0]['responseData']['custom_fields'];
    }


    // LEGACY
    public function getGroupCategoryData($getGroups='',$getCategories='')
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'legacy.retrieve_segment';

        $this->methods[$this->methodCount]['data']['return_group_data'] = $getGroups;
        $this->methods[$this->methodCount]['data']['return_category_data'] = $getCategories;

        $response = $this->hitServer();

        $dom = new DOMDocument();
        if (!$dom->loadXML($response[0]['responseData'])) {
            return false;
        }

        if(is_object($dom) && $dom->getElementsByTagName("manifest")->item(0)->hasChildNodes())
        {
            //Categories
            foreach($dom->getElementsByTagName("category_information") as $node)
            {
                foreach($node->childNodes as $dataNode)
                {
                    $temp[$dataNode->nodeName] = $dataNode->nodeValue;
                }

                $dataArray[categories][] = $temp;
                unset($temp);
            }

            //Groups
            foreach($dom->getElementsByTagName("group_information") as $node)
            {
                foreach($node->childNodes as $dataNode)
                {
                    $temp[$dataNode->nodeName] = $dataNode->nodeValue;
                }

                $dataArray[groups][] = $temp;
                unset($temp);
            }
        }

        return $dataArray;

    }

    public function editGroup($groupID,$groupName)
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'legacy.group_rename';

        $this->methods[$this->methodCount]['data']['group_id'] = $groupID;
        $this->methods[$this->methodCount]['data']['group_name'] = $groupName;

        // should be able to edit these in the future
        //$this->methods[$this->methodCount]['data']['hidden'] = $hidden;
        //$this->methods[$this->methodCount]['data']['category_id'] = $categoryID;

        return $this->hitServer();
    }

    public function clearOrRemoveGroups($groupID,$confirmationEmail = '',$removeGroup = '')
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'legacy.group_clear';

        $this->methods[$this->methodCount]['data']['group_id'] = $groupID;
        $this->methods[$this->methodCount]['data']['notify_email'] = $confirmationEmail;
        $this->methods[$this->methodCount]['data']['delete'] = $removeGroup; // Y or N


        return $this->hitServer();
    }


    /**
      *
      *
      */
    public function listRemoteSegmentTypes()
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'legacy.remote_segment';

        $this->methods[$this->methodCount]['data']['action'] = 'list';

        return $this->hitServer();
    }

    public function addRemoteSegmentType($xml_config)
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'legacy.remote_segment';

        $this->methods[$this->methodCount]['data']['action'] = 'add';
        $this->methods[$this->methodCount]['data']['xml_config'] = '<![CDATA[' . $xml_config . ']]>';

        return $this->hitServer();
    }

    public function updateRemoteSegmentType($xml_config,$remoteSegmentTypeID)
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'legacy.remote_segment';

        $this->methods[$this->methodCount]['data']['action'] = 'update';
        $this->methods[$this->methodCount]['data']['xml_config'] = '<![CDATA[' . $xml_config . ']]>';
        $this->methods[$this->methodCount]['data']['remote_segment_type_id'] = $remoteSegmentTypeID;

        return $this->hitServer();
    }

    public function deleteRemoteSegmentType($remoteSegmentTypeID)
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'legacy.remote_segment';

        $this->methods[$this->methodCount]['data']['action'] = 'delete';
        $this->methods[$this->methodCount]['data']['remote_segment_type_id'] = $remoteSegmentTypeID;

        return $this->hitServer();
    }


    public function searchSubscribers($data, $async = false)
    {
        // handling this different since the BH API is returning XML for this method even with the php request
        $this->setResponseType('xml');
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'legacy.retrieve_active';

        foreach($data as $key=>$value) {
            if($value) {
                $this->methods[$this->methodCount]['data'][$key] = $value;
            }
        }
        if($async) $this->methods[$this->methodCount]['data']['asynchronous'] = 1;

        $XMLresponse = $this->hitServer();

        $responseData = $this->parseXMLResponse($XMLresponse);
        $dom = new DOMDocument();
        if (!$dom->loadXML($responseData)) {
            return false;
        }
        $dataArray  = array();

        if($dom->getElementsByTagName("contact_data")->item(0)->childNodes)
        {
            foreach($dom->getElementsByTagName("contact_data") as $contact)
            {
                foreach($contact->childNodes as $node)
                {
                    if($node->nodeType == 1)
                    {
                        $temp[$node->nodeName] = $node->nodeValue;
                    }
                }

                $dataArray[] = $temp;
                unset($temp);
            }
        }

        $this->setResponseType('php');
        return $dataArray;
    }

    public function getSubscriberCount($data, $async = false)
    {
        // handling this different since the BH API is returning XML for this method even with the php request
        $this->setResponseType('xml');
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'legacy.retrieve_active';
        $this->methods[$this->methodCount]['data']['return_count'] = 1;

        foreach($data as $key=>$value) {
            if($value) {
                $this->methods[$this->methodCount]['data'][$key] = $value;
            }
        }
        if($async) $this->methods[$this->methodCount]['data']['asynchronous'] = 1;

        $XMLresponse = $this->hitServer();

        $responseData = $this->parseXMLResponse($XMLresponse);
        $dom = new DOMDocument();
        if (!$dom->loadXML($responseData)) {
            return false;
        }

        $this->setResponseType('php');
        return $dom->getElementsByTagName("count")->item(0)->nodeValue;
    }


    public function getSubscriber($email)
    {
        // handling this different since the BH API is returning XML for this method even with the php request
        $this->setResponseType('xml');
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'legacy.retrieve_active';

        foreach($data as $key=>$value) {
            if($value) {
                $this->methods[$this->methodCount]['data'][$key] = $value;
            }
        }

        $this->methods[$this->methodCount]['data']['email']          = $email;
        $this->methods[$this->methodCount]['data']['basic']          = 1;
        $this->methods[$this->methodCount]['data']['extended']       = 1;
        $this->methods[$this->methodCount]['data']['return_groups']  = 1;
        $this->methods[$this->methodCount]['data']['custom_fields']  = 1;

        $XMLresponse = $this->hitServer();

        $responseData = $this->parseXMLResponse($XMLresponse);
        $dom = new DOMDocument();
        if (!$dom->loadXML($responseData)) {
            return false;
        }
        $dataArray  = array();

        if($dom->getElementsByTagName("contact_data")->item(0)->childNodes)
        {
            foreach($dom->getElementsByTagName("contact_data")->item(0)->childNodes as $node)
            {
                if($node->nodeName == "groups_subscribed")
                {
                    foreach($node->getElementsByTagName("group_id") as $group)
                    {
                        $dataArray[groups][] = $group->nodeValue;
                    }
                }
                else if($node->nodeName == "custom_field_data")
                {
                    $fieldID    = $node->getElementsByTagName("custom_field_id")->item(0)->nodeValue;
                    $fieldValue = $node->getElementsByTagName("custom_field_value")->item(0)->nodeValue;

                    $dataArray["custval".$fieldID] = $fieldValue;
                }
                else if($node->nodeType == 1)
                {
                    $dataArray[$node->nodeName] = $node->nodeValue;
                }
            }
        }

        $this->setResponseType('php');
        return $dataArray;
    }

    /*
     * $sourceData is an array of either $sourceData['url'] or $sourceData['ftpServer'],
     *      $sourceData['ftpPassword'],$sourceData['ftpUsername'], and $sourceData['file']
     *
     */
    public function importSubscribers($reply_email,$file_type,$number,$source,$sourceData,$grp = '',$clear_group = '',$welcome_letter = '',$doi = '')
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'legacy.bulk_sync';

        $this->methods[$this->methodCount]['data']['reply_email'] = $reply_email;
        $this->methods[$this->methodCount]['data']['file_type'] = $file_type;
        $this->methods[$this->methodCount]['data']['number'] = $number;
        $this->methods[$this->methodCount]['data']['source'] = $this->wrapCDATA($source);
        $this->methods[$this->methodCount]['data']['grp'] = $grp;
        $this->methods[$this->methodCount]['data']['clear_grp'] = $clear_group;
        $this->methods[$this->methodCount]['data']['welcome_letter'] = $welcome_letter;
        $this->methods[$this->methodCount]['data']['doi'] = $doi;
        if($sourceData['url']){
            $this->methods[$this->methodCount]['data']['data_url'] = $this->wrapCDATA($sourceData['url']);
        }else{
            $this->methods[$this->methodCount]['data']['ftp_server'] = $sourceData['ftpServer'];
            $this->methods[$this->methodCount]['data']['ftp_user_pass'] = $sourceData['ftpPassword'];
            $this->methods[$this->methodCount]['data']['ftp_user_name'] = $sourceData['ftpUsername'];
            $this->methods[$this->methodCount]['data']['filename'] = $sourceData['file'];
            $this->methods[$this->methodCount]['data']['ftp_ssl'] = $sourceData['ssl']; // doesn't work
        }

        $response = $this->hitServer();

        return $response[0]['responseData'];
    }

    public function bulkDeleteSubscribers($confirmEmail,$dataURL,$optout = 'N',$ftpData='')
    {
        $this->incrementMethodCount();
        $this->methods[$this->methodCount]['methodName'] = 'legacy.delete_subscribers';

        //required
        $this->methods[$this->methodCount]['data']['reply_email'] = $confirmEmail;
        $this->methods[$this->methodCount]['data']['optout'] = $optout; // Y or N, default N

        if($dataURL){
            $this->methods[$this->methodCount]['data']['data_url'] = $dataURL;
        }else{
            $this->methods[$this->methodCount]['data']['ftp_server'] = $ftpData['server'];
            $this->methods[$this->methodCount]['data']['ftp_user_name'] = $ftpData['username'];
            $this->methods[$this->methodCount]['data']['ftp_user_pass'] = $ftpData['password'];
            $this->methods[$this->methodCount]['data']['filename'] = $ftpData['filename'];
        }

        return $this->hitServer();
    }



    /*
     *  Message methods
     */
    public function prepareMessage($subject,$htmlMessage,$textMessage,$staticSegments,$dynamicSegments,
                      $excludedStaticSegments,$excludedDynamicSegments,$replyEmail,$fromEmail,$fromDescription,
                      $billCodes = '',$trackLinks = '1',$options=array())
    {
        $this->incrementMethodCount();
//mail('adam@bandfarm.com','m_data',print_r($trackLinks,true),'from:sentmessage');
        $this->methods[$this->methodCount]['methodName'] = 'legacy.send_campaign';

        if(is_array($staticSegments)){
            $this->methods[$this->methodCount]['data']['grp'] = implode(',',$staticSegments);
        }

        if(is_array($excludedStaticSegments)){
            $this->methods[$this->methodCount]['data']['grp_exclude'] = implode(',',$excludedStaticSegments);
        }

        if(is_array($dynamicSegments)){
            $this->methods[$this->methodCount]['data']['sm'] = implode(',',$dynamicSegments);
        }

        if(is_array($excludedDynamicSegments)){
            $this->methods[$this->methodCount]['data']['sm_exclude'] = implode(',',$excludedDynamicSegments);
        }

        // required
        $this->methods[$this->methodCount]['data']['rich_mbody'] = '<![CDATA[ ' . $htmlMessage . ' ]]>';
        $this->methods[$this->methodCount]['data']['text_mbody'] = '<![CDATA[ ' . $textMessage . ' ]]>';
        $this->methods[$this->methodCount]['data']['reply_email'] = $replyEmail;
        $this->methods[$this->methodCount]['data']['from_email'] = $fromEmail;
        $this->methods[$this->methodCount]['data']['fromdesc'] = '<![CDATA[' . $fromDescription . ']]>';
        $this->methods[$this->methodCount]['data']['msubject'] = '<![CDATA[' . $subject . ']]>';

        // optional
        $sendMessage = 'Y';
        if($sendMessage) $this->methods[$this->methodCount]['data']['send'] = $sendMessage; // Y
        if($billCodes) $this->methods[$this->methodCount]['data']['bill_codes'] = $billCodes;
        //if($trackLinks) $this->methods[$this->methodCount]['data']['track_links'] = $trackLinks;
        $this->methods[$this->methodCount]['data']['track_links'] = '1';
        if($options['substituteName']) $this->methods[$this->methodCount]['data']['substitute_name'] = $options['substituteName'];
        if($options['messageNotes']) $this->methods[$this->methodCount]['data']['message_notes'] = $options['messageNotes'];
        if($options['campaignID']) $this->methods[$this->methodCount]['data']['campaign_id'] = $options['campaignID'];
        if($options['useDefaultFooter']) $this->methods[$this->methodCount]['data']['use_default_footer'] = $options['useDefaultFooter'];

        //time release
        if($options['scheduled'] == 'Y'){
            $this->methods[$this->methodCount]['data']['timed_release'] = 'Y'; //(Y if true)
            $this->methods[$this->methodCount]['data']['date'] = $options['date']; // YYYY-MM-DD
            $this->methods[$this->methodCount]['data']['hour'] = $options['hour']; // 24hr
         }

        $this->methods[$this->methodCount]['data']['track_links'] = '1';

        $response = $this->hitServer();

        return $response[0]['responseData'];
    }

    // send an already prepared message
    public function sendMessage($messageKey)
    {
        $this->incrementMethodCount();

        if(!$messageKey){
            return false;
        }

        $this->methods[$this->methodCount]['methodName'] = 'legacy.send_campaign';

        $this->methods[$this->methodCount]['data']['message_key'] = $messageKey;

        $response = $this->hitServer();

        return $response[0]['responseData'];
    }






    public function getMessageStatsByMessageID($messageID)
    {
        $this->incrementMethodCount();
        $this->methods[$this->methodCount]['methodName'] = 'legacy.message_stats';

        //required
        $this->methods[$this->methodCount]['data']['mess_id'] = $messageID;

        $response = $this->hitServer();

        $response = $this->parseMessageStatsXML($response[0]['responseData']);

        return $response[$messageID];
    }

    //by default will get the last 100 messages
    public function getMessageStatsByRange($last = '',$startDate = '',$endDate = '')
    {
        $this->incrementMethodCount();
        $this->methods[$this->methodCount]['methodName'] = 'legacy.message_stats';

        //required
        $this->methods[$this->methodCount]['data']['last'] = $last;
        if($startDate==$endDate || ($startDate && !$endDate)){
      $this->methods[$this->methodCount]['data']['date'] = $startDate;
        }else{
      $this->methods[$this->methodCount]['data']['start_date'] = $startDate;
      $this->methods[$this->methodCount]['data']['end_date'] = $endDate;
        }

        $response = $this->hitServer();

        return $this->parseMessageStatsXML($response[0]['responseData']);
    }


    public function getSubscriberMessageData($messageID, $startDate = '', $endDate = '', $dataTypes = '')
    {

        $this->incrementMethodCount();
        $this->methods[$this->methodCount]['methodName'] = 'statistics.getSubscriberMessageData';

        //required
      $this->methods[$this->methodCount]['data']['start_date'] = $startDate;
      $this->methods[$this->methodCount]['data']['end_date'] = $endDate;
      $this->methods[$this->methodCount]['data']['data_types'] = $dataTypes;

        $response = $this->hitServer();

        return $this->parseMessageStatsXML($response[0]['responseData']);
    }


    // ------------ Transactional Messaging ---------------
    public function insertTemplate($subject,$fromDescription,$fromEmail,$replyEmail,$htmlContent,$plainContent,$trackLinks = '',$trackROI = '')
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'transactional.insertTemplate';

        $templateData = "<html>
                            <![CDATA[ {$htmlContent} ]]>
                        </html>
                        <plain>
                            <![CDATA[ {$plainContent} ]]>
                        </plain>
                        ";


        $this->methods[$this->methodCount]['data']['subject'] = '<![CDATA[ '.$subject.']]>';
        $this->methods[$this->methodCount]['data']['from_description'] = '<![CDATA[ '.$fromDescription.']]>';
        $this->methods[$this->methodCount]['data']['from_email'] = $fromEmail;
        $this->methods[$this->methodCount]['data']['reply_email'] = $replyEmail;
        $this->methods[$this->methodCount]['data']['template_data'] = $templateData;
        $this->methods[$this->methodCount]['data']['trackLinks'] = $track_links;
        $this->methods[$this->methodCount]['data']['trackROI'] = $track_roi;

        return $this->hitServer();
    }


    public function updateTemplate($template_id,$subject,$fromDescription,$fromEmail,$replyEmail,$htmlContent,$plainContent,$trackLinks = NULL,$trackROI = NULL)
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'transactional.updateTemplate';

        if($htmlContent && $plainContent){
            $templateData = "<html>
                                <![CDATA[ {$htmlContent} ]]>
                            </html>
                            <plain>
                                <![CDATA[ {$plainContent} ]]>
                            </plain>
                            ";
        }

        $this->methods[$this->methodCount]['data']['template_id'] = $template_id;

        if($subject) $this->methods[$this->methodCount]['data']['subject'] = '<![CDATA[ '.$subject.']]>';
        if($fromDescription) $this->methods[$this->methodCount]['data']['from_description'] = '<![CDATA[ '.$fromDescription.']]>';
        if($fromEmail) $this->methods[$this->methodCount]['data']['from_email'] = $fromEmail;
        if($replyEmail) $this->methods[$this->methodCount]['data']['reply_email'] = $replyEmail;
        if($templateData) $this->methods[$this->methodCount]['data']['template_data'] = $templateData;

        if(isset($track_links)) $this->methods[$this->methodCount]['data']['trackLinks'] = $track_links;
        if(isset($track_roi)) $this->methods[$this->methodCount]['data']['trackROI'] = $track_roi;

        return $this->hitServer();
    }


    public function rebuildTemplate($template_id)
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'transactional.rebuildTemplate';

        $this->methods[$this->methodCount]['data']['template_id'] = $template_id;

        return $this->hitServer();
    }


    public function listTemplates($template_id = null)
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'transactional.listTemplates';

        return $this->hitServer();
    }


    public function sendTransaction($email,$template_id,$emailPreference,$contactAdd,$data)
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'transactional.sendTransaction';

        $this->methods[$this->methodCount]['data']['email'] = $email;
        $this->methods[$this->methodCount]['data']['template_id'] = $template_id;
        $this->methods[$this->methodCount]['data']['email_preference'] = $emailPreference;
        $this->methods[$this->methodCount]['data']['contact_add'] = $contactAdd;

        foreach($data as $key=>$value){
            $this->methods[$this->methodCount]['data'][$key] = $this->data2params($value);
        }

        //print_r($this->methods[$this->methodCount]['data']);

        return $this->hitServer();
    }


    public function sendTest($template_id)
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'transactional.sendTest';

        return $this->hitServer();
    }


    public function retrieveUnsubscribes($startDate,$endDate,$messageID = '',$email = '')
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'legacy.retrieve_unsub';

        $this->methods[$this->methodCount]['data']['date_deleted1'] = $startDate;
        $this->methods[$this->methodCount]['data']['date_deleted2'] = $endDate;
        $this->methods[$this->methodCount]['data']['email'] = $email;

        return $this->hitServer();
    }




    // ------------ Utilities ---------------
    public function checkEmail($email,$domainOnly = '',$mxCheck = '')
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'utilities.checkemail';

        $this->methods[$this->methodCount]['data']['email'] = $email;
        if($domainOnly) $this->methods[$this->methodCount]['data']['domain_only'] = 1;
        if($mxCheck) $this->methods[$this->methodCount]['data']['mx_check'] = 1;

        return $this->hitServer();
    }

    public function listFiles()
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'utilities.listFiles';

        $response = $this->hitServer();

        return $this->parseMessageStatsXML($response[0]['responseData']);
    }

    public function getFile($file)
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'utilities.getFile';

        $this->methods[$this->methodCount]['data']['file'] = $file;

        return $this->hitServer(true);
    }


    public function insertROIData($roiData,$amount,$orderID,$ignoreDuplicateOrders='',$datePurchased='',$dateFormat='')
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'roi.insert';

        $this->methods[$this->methodCount]['data']['roi_data'] = $roiData;
        $this->methods[$this->methodCount]['data']['amount'] = $amount;
        $this->methods[$this->methodCount]['data']['order_id'] = $orderID;

        //optional
        if($ignoreDuplicateOrders) $this->methods[$this->methodCount]['data']['ignore_duplicate_orders'] = $ignoreDuplicateOrders;
        if($datePurchased) $this->methods[$this->methodCount]['data']['purchase_date'] = $datePurchased;
        if($dateFormat) $this->methods[$this->methodCount]['data']['date_format'] = $dateFormat;

        return $this->hitServer();
    }


    // utilities
    /*
     * refer to http://echo.bluehornet.com/api_docs/index/method/method/utilities.getTasks for $data array values
     * @param array $data
     * @return string
     */
    public function getTask($task_id)
    {


      $response = $this->getTasks(array('task_id'=>$task_id));



        return $response['task']['0'];

    }

    public function getTasks($data)
    {
      $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'utilities.getTasks';

        if($data['task_id']) $this->methods[$this->methodCount]['data']['task_id'] = $data['task_id'];
        if($data['status']) $this->methods[$this->methodCount]['data']['status'] = $data['status'];
        if($data['type']) $this->methods[$this->methodCount]['data']['type']   = $data['type'];
        if($data['start_date']) $this->methods[$this->methodCount]['data']['start_date'] = $data['start_date'];
        if($data['end_date']) $this->methods[$this->methodCount]['data']['end_date'] = $data['end_date'];

        $response = $this->hitServer();

        return $response[0]['responseData'];

    }


    // stats
    public function getMessageSubscriberData($messageID,$startDate = null,$endDate = null, $types = '')
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'statistics.getMessageSubscriberData';

        // required
        $this->methods[$this->methodCount]['data']['mess_id'] = $messageID;

        // optional
        if($startDate) $this->methods[$this->methodCount]['data']['start_date'] = $startDate;
        if($endDate) $this->methods[$this->methodCount]['data']['end_date']   = $endDate;

        $this->methods[$this->methodCount]['data']['action_types']   = $types;

        $response = $this->hitServer();

        return $response[0]['responseData'];
    }

    /********** Beta Methods *************/
    public function createCustomField($fieldName,$fieldType = 'string',$dateFormat = 'MM/DD/YYYY',$displayOnSurvey = null)
    {
        $this->incrementMethodCount();

      $this->methods[$this->methodCount]['methodName'] = 'account.addCustomField';

        $this->methods[$this->methodCount]['data']['field_name'] = $fieldName;
        $this->methods[$this->methodCount]['data']['field_type'] = $fieldType;
        $this->methods[$this->methodCount]['data']['date_format']   = $dateFormat;
        $this->methods[$this->methodCount]['data']['display_on_survey'] = $displayOnSurvey;

      return $this->hitServer();
    }

    /*
    public function createCustomField($fieldName,$fieldType = 'string',$dateFormat = 'MM/DD/YYYY',$displayOnSurvey = null)
    {
        $this->incrementMethodCount();

      $this->methods[$this->methodCount]['methodName'] = 'account.addCustomField';

        $this->methods[$this->methodCount]['data']['field_name'] = $fieldName;
        $this->methods[$this->methodCount]['data']['field_type'] = $fieldType;
        $this->methods[$this->methodCount]['data']['date_format']   = $dateFormat;
        $this->methods[$this->methodCount]['data']['display_on_survey'] = $displayOnSurvey;

      return $this->hitServer();
    }

    public function createCustomField($fieldName,$fieldType = 'string',$dateFormat = 'MM/DD/YYYY',$displayOnSurvey = null)
    {
        $this->incrementMethodCount();

      $this->methods[$this->methodCount]['methodName'] = 'account.addCustomField';

        $this->methods[$this->methodCount]['data']['field_name'] = $fieldName;
        $this->methods[$this->methodCount]['data']['field_type'] = $fieldType;
        $this->methods[$this->methodCount]['data']['date_format']   = $dateFormat;
        $this->methods[$this->methodCount]['data']['display_on_survey'] = $displayOnSurvey;

      return $this->hitServer();
    }
    */


    /********** Reseller Methods *************/
    public function createClientAccount($data)
    {
        $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'reseller.createClient';

        $this->methods[$this->methodCount]['data']['username'] = $data['username'];
        $this->methods[$this->methodCount]['data']['password'] = $data['password'];
        //$this->methods[$this->methodCount]['data']['rep_id']   = $data['sales_rep_id'];
        $this->methods[$this->methodCount]['data']['business_name'] = $data['businessName'];
        $this->methods[$this->methodCount]['data']['contact_name'] = $data['contactName'];
        $this->methods[$this->methodCount]['data']['address'] = $data['address'];
        $this->methods[$this->methodCount]['data']['city'] = $data['city'];
        $this->methods[$this->methodCount]['data']['state'] = $data['state'];
        $this->methods[$this->methodCount]['data']['postal_code'] = $data['postalCode'];
        $this->methods[$this->methodCount]['data']['phone'] = $data['phone'];
        $this->methods[$this->methodCount]['data']['fax'] = $data['fax'];
        $this->methods[$this->methodCount]['data']['email'] = $data['email'];
        $this->methods[$this->methodCount]['data']['url'] = $data['url'];
        $this->methods[$this->methodCount]['data']['powered_by_logo'] = $data['poweredBy'];
        $this->methods[$this->methodCount]['data']['trial_period'] = $data['trialPeriod'];
        $this->methods[$this->methodCount]['data']['storage'] = $data['storage'];
        //$this->methods[$this->methodCount]['data']['customer_id'] = $data['customer_id'];

        $features = explode(',',$data['features']);

        foreach($features as $feature){
            $client_features .= "<{$feature}>1</{$feature}>\n";
        }

        $this->methods[$this->methodCount]['data']['client_features'] = $client_features;

        $response = $this->hitServer();

        if(array_key_exists('error',$response[0])) return $response[0];

        return $response[0]['responseData'];
    }
  /*
  public function createAccount($data)
  {
      $this->incrementMethodCount();

        $this->methods[$this->methodCount]['methodName'] = 'reseller.createAccount';

        if($data['username']){
          $account_info['username'] = $data['username'];
        }else{
          $account_info['username'] = time();
        }
        if($data['password']){
          $account_info['password'] = $data['password'];
        }else{
          $account_info['password'] = time();
        }

        $account_info['businessname'] = $data['business_name'];
        $account_info['contactname'] = $data['contact_name'];
        $account_info['address'] = $this->address;
        $account_info['city'] = $this->city;
        $account_info['state'] = $this->state;
        $account_info['postal_code'] = $this->postal_code;
        $account_info['phone'] = $this->phone;
        $account_info['fax'] = $this->fax;
        $account_info['clientemail'] = $data['email'];
        $account_info['client_url'] = $this->url;
        $account_info['powered_logo'] = 1;
        $account_info['trialperiod'] = $this->trial_period;
        $account_info['storage'] = 1000000;
        $account_info['customer_id'] = $this->customer_id;


        return $this->hitServer();

  }
    */

    //
    private function data2params($dataArray)
    {

        if(!is_array($dataArray)){
            return "<![CDATA[ {$dataArray} ]]>";
        }

        foreach ($dataArray as $key=>$value){
            if(is_array($value)){
                $return .= "<{$key}>" . $this->data2params($value) . "</{$key}>";
            }else{
                $return .= "<{$key}><![CDATA[{$value}]]></{$key}>\n";
            }
        }

        return $return;
    }

    private function wrapCDATA($str)
    {
      return "<![CDATA[{$str}]]>";
    }

    // XTRAS


    //
    public function parseXMLResponse($xmlstr)
    {
        $xml = new SimpleXMLElement($xmlstr);

        return $xml->item->responseData->manifest->asXML();
    }


    private function xml2Array($xmlstr)
    {
        $xml = new SimpleXMLElement($xmlstr);

        return json_decode(json_encode($xml),true);
    }



  private function parseStats($xml)
  {

        $dom = new DOMDocument();
        if (!$dom->loadXML($xml)) {
            return false;
        }

        $dataArray  = array();

        if(get_class($dom) == "DOMDocument" and $dom->getElementsByTagName("message_data"))
        {
            //Categories
            foreach($dom->getElementsByTagName("message") as $node)
            {
                $date_sent = $node->getElementsByTagName("date_sent")->item(0)->nodeValue;

                $dataArray[] = array(
                    "id"                => $node->getAttribute("id"),
                    "date_sent"         => $date_sent,
                    "date"              => date("Y-m-d", strtotime($date_sent)),
                    "message_subject"   => $node->getElementsByTagName("message_subject")->item(0)->nodeValue,
                    "message_notes"     => $node->getElementsByTagName("message_notes")->item(0)->nodeValue,
                    "sent_total"        => $node->getElementsByTagName("sent_total")->item(0)->nodeValue,
                  "opened_rate_unique"=> $node->getElementsByTagName("opened_rate_unique")->item(0)->nodeValue
          );
            }
        }



        return $dataArray;
  }


    //------------------------------Get Sent Message Detail----------------
    // until we can collect by mess_id we will collect the day and get the one we want
    public function parseMessageStatsXML($xml)
    {
//error_reporting(E_ALL);
        $dom = new DOMDocument();
        if (!$dom->loadXML($xml)) {
            return false;
        }

//Zend_Debug::dump($dom,'dom');
        $dataArray  = array();

        //Testing
        #echo "<pre>";
        #echo htmlentities($dom->saveHTML());
        #echo "</pre>";
        #exit();

        if($dom->getElementsByTagName("message_data"))
        {
            //Categories
            foreach($dom->getElementsByTagName("message") as $m_node)
            {

                $messID = (int)$m_node->getAttribute("id");

                $dataArray[$messID] = array(
                    "id"                => $m_node->getAttribute("id"),
                    "date_sent"         => $m_node->getElementsByTagName("date_sent")->item(0)->nodeValue,
                    "message_subject"       => $m_node->getElementsByTagName("message_subject")->item(0)->nodeValue,
                    "message_notes"         => $m_node->getElementsByTagName("message_notes")->item(0)->nodeValue,
                    "sent_total"            => $m_node->getElementsByTagName("sent_total")->item(0)->nodeValue,

                    "sent_total_html"       => $m_node->getElementsByTagName("sent_total_html")->item(0)->nodeValue,
                    "sent_total_plain"      => $m_node->getElementsByTagName("sent_total_plain")->item(0)->nodeValue,
                    "sent_rate_total"       => $m_node->getElementsByTagName("sent_rate_total")->item(0)->nodeValue,
                    "sent_rate_html"        => $m_node->getElementsByTagName("sent_rate_html")->item(0)->nodeValue,
                    "sent_rate_plain"       => $m_node->getElementsByTagName("sent_rate_plain")->item(0)->nodeValue,

                    "delivered_total"       => $m_node->getElementsByTagName("delivered_total")->item(0)->nodeValue,
                    "delivered_html"        => $m_node->getElementsByTagName("delivered_html")->item(0)->nodeValue,
                    "delivered_plain"       => $m_node->getElementsByTagName("delivered_plain")->item(0)->nodeValue,
                    "delivered_rate_total"      => $m_node->getElementsByTagName("delivered_rate_total")->item(0)->nodeValue,
                    "delivered_rate_html"       => $m_node->getElementsByTagName("delivered_rate_html")->item(0)->nodeValue,

                    "delivered_rate_plain"      => $m_node->getElementsByTagName("delivered_rate_plain")->item(0)->nodeValue,
                    "bounced_total"     => $m_node->getElementsByTagName("bounced_total")->item(0)->nodeValue,
                    "bounced_html"      => $m_node->getElementsByTagName("bounced_html")->item(0)->nodeValue,
                    "bounced_plain"     => $m_node->getElementsByTagName("bounced_plain")->item(0)->nodeValue,
                    "bounced_rate_total"        => $m_node->getElementsByTagName("bounced_rate_total")->item(0)->nodeValue,

                    "bounced_rate_html"     => $m_node->getElementsByTagName("bounced_rate_html")->item(0)->nodeValue,
                    "bounced_rate_plain"        => $m_node->getElementsByTagName("bounced_rate_plain")->item(0)->nodeValue,
                    "invalid_total"     => $m_node->getElementsByTagName("invalid_total")->item(0)->nodeValue,
                    "invalid_rate_total"        => $m_node->getElementsByTagName("invalid_rate_total")->item(0)->nodeValue,
                    "optout_total"      => $m_node->getElementsByTagName("optout_total")->item(0)->nodeValue,

                    "optout_rate_total"     => $m_node->getElementsByTagName("optout_rate_total")->item(0)->nodeValue,
                    "clicked_total"     => $m_node->getElementsByTagName("clicked_total")->item(0)->nodeValue,
                    "clicked_unique"        => $m_node->getElementsByTagName("clicked_unique")->item(0)->nodeValue,
                    "clicked_rate_unique"       => $m_node->getElementsByTagName("clicked_rate_unique")->item(0)->nodeValue,
                    "clicked_rate_aps"      => $m_node->getElementsByTagName("clicked_rate_aps")->item(0)->nodeValue,

                    "opened_total"      => $m_node->getElementsByTagName("opened_total")->item(0)->nodeValue,
                    "opened_unique"     => $m_node->getElementsByTagName("opened_unique")->item(0)->nodeValue,
                    "opened_rate_unique"        => $m_node->getElementsByTagName("opened_rate_unique")->item(0)->nodeValue,
                    "opened_rate_aps"       => $m_node->getElementsByTagName("opened_rate_aps")->item(0)->nodeValue,
                    "campaign_name"     => $m_node->getElementsByTagName("campaign_name")->item(0)->nodeValue,
                    "campaign_id"       => $m_node->getElementsByTagName("campaign_id")->item(0)->nodeValue,

                    "has_dynamic_content"       => $m_node->getElementsByTagName("has_dynamic_content")->item(0)->nodeValue,
                    "has_delivery_report"       => $m_node->getElementsByTagName("has_delivery_report")->item(0)->nodeValue,
                    "link_append_statement"     => $m_node->getElementsByTagName("link_append_statement")->item(0)->nodeValue,
                    "ftf_forwarded"     => $m_node->getElementsByTagName("ftf_forwarded")->item(0)->nodeValue,
                    "ftf_signups"       => $m_node->getElementsByTagName("ftf_signups")->item(0)->nodeValue,
                    "ftf_conversion_rate"       => $m_node->getElementsByTagName("ftf_conversion_rate")->item(0)->nodeValue,
                    );
                //included segments
                foreach($m_node->getElementsByTagName("included_groups") as $g_node)
                {
                   $id = $g_node->getAttribute("id");
                    $dataArray[$messID]["included_groups"]["$id"] = $g_node->getElementsByTagName("segment")->item(0)->nodeValue;
                }

                foreach($m_node->getElementsByTagName("included_smartlists") as $g_node)
                {
                   $id = $g_node->getAttribute("id");
                    $dataArray[$messID]["included_smartlists"]["$id"] = $g_node->getElementsByTagName("segment")->item(0)->nodeValue;
                }

                foreach($m_node->getElementsByTagName("excluded_groups") as $g_node)
                {
                   $id = $g_node->getAttribute("id");
                    $dataArray[$messID]["excluded_groups"]["$id"] = $g_node->getElementsByTagName("segment")->item(0)->nodeValue;
                }

                foreach($m_node->getElementsByTagName("excluded_smartlists") as $g_node)
                {
                   $id = $g_node->getAttribute("id");
                    $dataArray[$messID]["excluded_smartlists"]["$id"] = $g_node->getElementsByTagName("segment")->item(0)->nodeValue;
                }

                //links
                foreach($m_node->getElementsByTagName("link") as $l_node)
                {
                   $id = $l_node->getAttribute("id");
                    $dataArray[$messID]["link"]["$id"] = array(
                        "url"       =>  $l_node->getElementsByTagName("url")->item(0)->nodeValue,
                        "url_name"       =>  $l_node->getElementsByTagName("url_name")->item(0)->nodeValue,
                        "url_display"       =>  $l_node->getElementsByTagName("url_display")->item(0)->nodeValue,
                        "has_name"       =>  $l_node->getElementsByTagName("has_name")->item(0)->nodeValue,
                        "clicked_unique_total"       =>  $l_node->getElementsByTagName("clicked_unique_total")->item(0)->nodeValue,

                        "clicked_total_plain"       =>  $l_node->getElementsByTagName("clicked_total_plain")->item(0)->nodeValue,
                        "clicked_unique_plain"       =>  $l_node->getElementsByTagName("clicked_unique_plain")->item(0)->nodeValue,
                        "clicked_total_html"       =>  $l_node->getElementsByTagName("clicked_total_html")->item(0)->nodeValue,
                        "clicked_unique_html"       =>  $l_node->getElementsByTagName("clicked_unique_html")->item(0)->nodeValue,
                        "clicked_rate_total"       =>  $l_node->getElementsByTagName("clicked_rate_total")->item(0)->nodeValue,
                        "roi_conversions"       =>  $l_node->getElementsByTagName("roi_conversions")->item(0)->nodeValue,
                        "roi_total"       =>  $l_node->getElementsByTagName("roi_total")->item(0)->nodeValue,
                        "roi_average"       =>  $l_node->getElementsByTagName("roi_average")->item(0)->nodeValue,

                      );
                }

            }
        }

        return $dataArray;

    }

}



