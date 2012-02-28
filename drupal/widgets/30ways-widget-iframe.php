<?php

$xmlFile = $_SERVER['HTTP_HOST']."/calendar/xml/20673";

# xml file location
try {
  $theXml = simplexml_load_file($xmlFile);
} catch (Exception $e) {
  $theXml = false;
}

# if stream wrappers fail:
if (!$theXml) {
  if (!function_exists('curl_init')) {
    throw new Exception('Curl is not installed.');
  } else {
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $xmlFile);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ch, CURLOPT_TIMEOUT, 10);
    $rawXml = curl_exec($ch);
    curl_close($ch);
    $theXml = simplexml_load_string($rawXml);
  }
}

# parse xml
$todays_date =  $theXml->action[0]->todays_date;
$topic_icon = $theXml->action[0]->topic_icon;
$action_title = $theXml->action[0]->action_title;
$action_page = $theXml->action[0]->action_page;
$calendar_page = $theXml->action[0]->calendar_page;

# fix timestamp
$today = strtoupper(date("M j",((int)($todays_date))));
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>30 Ways: Widget</title>
<style type="text/css">
<!--
body { 
	margin: 0px; 
	padding: 0px;
	background-color: #FFFFFF;
	font-family: helvetica, arial, sans-serif;
	font-weight: bold;
	color: #000000;
}
#mainDiv {
	width: 300px;
	height: 250px;
	background-image: url('widget-cal.png');
	background-repeat: no-repeat;
}
#dateBox {
	position: absolute;
	top: 54px;
	left: 225px;
	padding: 5px 7px 4px 7px;
	background-color: #99BBCC;
	color: #FFFFFF; 
	font-size: 13px;
	text-align: left;
}
#topicIcon {
	position: absolute;
	top: 55px;
	left: 28px;
}
#headline {
	position: absolute;
	top: 87px;
	left: 28px;
	width: 245px;
	font-size: 14px;
	line-height: 20px;
	text-align: left;
}
#headline a {
	text-decoration: none;
	color: #000000;
}
#headline a:hover {
	text-decoration: none;
	color: #000000;
}
#actionButton {
	position: absolute;
	top: 135px;
	left: 49px;
}
#fullCalendar {
	position: absolute;
	top: 199px;
	width: 300px;
	text-align: center;
	font-size: 11px;
	text-transform: uppercase;
}
#fullCalendar a {
	text-decoration: none;
	color: #1CA9E7;
}
#fullCalendar a:hover {
	text-decoration: underline;
}
-->
</style>

<script language="JavaScript">
<!--
function changeimg() {
	if (document.images) {
		for (var i=0; i<changeimg.arguments.length; i+=2) {
			document[changeimg.arguments[i]].src = eval(changeimg.arguments[i+1] + ".src");
    	}
  	}
}
if (document.images) {
	actionBut_on = new Image();
	actionBut_on.src = "TATP_Button200x50-rollover.png";
	actionBut_off = new Image();
	actionBut_off.src = "TATP_Button200x50.png";
}
// -->
</script>

</head>
<body>

<div id="mainDiv">

	<div id="topicIcon"><?php echo $topic_icon; ?><br></div>

	<div id="dateBox"><?php echo $today; ?><br></div>

	<div id="headline"><a href="<?php echo $action_page; ?>?cmpid=30wayswidget" target="_top"><?php echo $action_title; ?></a><br></div>

	<div id="actionButton"><a href="<?php echo $action_page; ?>?cmpid=30wayswidget" target="_top" onMouseOver="changeimg('actionBut', 'actionBut_on');" onMouseOut="changeimg('actionBut', 'actionBut_off');"><img src="TATP_Button200x50.png" name="actionBut" width="200" height="50" border="0" alt="Take Action with TakePart"></a><br></div>

	<div id="fullCalendar"><a href="<?php echo $calendar_page; ?>?cmpid=30wayswidget" target="_top">View Full 30 Ways Calendar</a><br></div>

</div>

</body>
</html>

<?php
exit;
?>