<?php



function readCSV() {

  $handle = @fopen(dirname(__FILE__) . "/constituent_download_20120824-165616.csv", "r");
  if ($handle) {

    $firstcnt = 0;
    $lastcnt = 0;
    $addrcnt = 0;
    $citycnt = 0;
    $statecnt = 0;
    $zipcnt = 0;
    $countrycnt = 0;
    $emailcnt = 0;
    $processedcnt = 0;
    $entrycnt = 0;
    $failcnt = 0;

    $stub = "_unknown_";
    $emaildupecheck = array();
    $starttime = microtime();

    while (($data = fgetcsv($handle, ",")) !== FALSE) {

      $processedcnt++;

      $num = count($data);

      if (($num == 8) && ($processedcnt != 1)) {

        $row++;

        if(isset($data[0]) && trim($data[0]) != '') {
          $first = $data[0];
        } else {
          $first = $stub;
          $firstcnt++;
        }

        if(isset($data[1]) && trim($data[1]) != '') {
          $last = $data[1];
        } else {
          $last = $stub;
          $lastcnt++;
        }

        if(isset($data[2]) && trim($data[2]) != '') {
          $addr = $data[2];
        } else {
          $addr = $stub;
          $addrcnt++;
        }

        if(isset($data[3]) && trim($data[3]) != '') {
          $city = $data[3];
        } else {
          $city = $stub;
          $citycnt++;
        }

        if(isset($data[4]) && trim($data[4]) != '') {
          $state = $data[4];
        } else {
          $state = $stub;
          $statecnt++;
        }

        if(isset($data[5]) && trim($data[5]) != '') {
          $zip = $data[5];
        } else {
          $zip = $stub;
          $zipcnt++;
        }

        if(isset($data[6]) && trim($data[6]) != '') {
          $country = $data[6];
        } else {
          $country = $stub;
          $countrycnt++;
        }

        if(isset($data[7]) && trim($data[7]) != '') {
          $email = $data[7];
          if (!in_array($email, $emaildupecheck)) {

            $entry = save_signature('27667', $email, $first, $last, $addr, $city, $state, $zip, $country);

            if($entry) {
              $entrycnt++;
              //echo "\n" .$entrycnt . " " . $email . ".";
            } else {
              $failcnt++;
              echo "\nFailed to save " . $email . ".";
            }

            array_push($emaildupecheck, $email);
          } else {
            echo "\Skipping duplicate record: " . $email;
          }

        }


      } else {
        echo "\n Skipping line $processedcnt with $num fields.\n";
      }


    }

    $endtime = microtime();
    echo "\nProcessed " . $processedcnt . " lines.";
    echo "\nSaved " . $entrycnt . " entries.";
    echo "\nProcess took " . ($endtime - $starttime) . " seconds.";
    echo "\n" . $failcnt . " failed.";
    echo "\nMissing ... ";
    echo "\nFirst names: " . $firstcnt;
    echo "\nLast names: " . $lastcnt;
    echo "\nAddr: " . $addrcnt;
    echo "\nCity: " . $citycnt;
    echo "\nState: " . $statecnt;
    echo "\nZIP: " . $zipcnt;
    echo "\nCountry: " . $countrycnt;
    echo "\nEmails: " . $emailcnt;

    if (!feof($handle)) {
      echo "Error: unexpected fgets() fail\n";
    }
    fclose($handle);
  } else {
    echo "Failed to open file.\n";
  }
}


function text_field($value = NULL) {
  if (isset($value)) {
    return array(LANGUAGE_NONE => array(array('value' => $value)));
  }
  return array(LANGUAGE_NONE => array());
}

function save_signature($nid, $email, $first_name, $last_name, $addr, $city, $state, $zip, $country) {
  
  // Create the signature with it's properties pre-initialized.
  $signature = entity_create('signature', array(
      'type' => 'international_signature',
      'nid' => $nid,
      'email' => $email,
      'display' => 0,
      'newsletter' => 0,
  ));

  // Required fields.
  $signature->field_sign_first_name = text_field($first_name);
  $signature->field_sign_last_name = text_field($last_name);
  $signature->field_sig_address = text_field($addr);
  $signature->field_sig_city = text_field($city);

  // Optional fields.
  $signature->field_sig_state = text_field($state);
  $signature->field_sig_zip_code = text_field($zip);
  $signature->field_sig_country = text_field($country);
  $signature->field_sig_postal_code = text_field();

  // Save the signature to the database.
  return entity_save('signature', $signature);
}


readCSV();

