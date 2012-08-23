<?php

function text_field($value = NULL) {
  if (isset($value)) {
    return array(LANGUAGE_NONE => array(array('value' => $value)));
  }
  return array(LANGUAGE_NONE => array());
}

function save_signature($nid, $email, $first_name, $last_name) {

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
  $signature->field_sig_address = text_field('123 Place Holder St.');
  $signature->field_sig_city = text_field('Townsville');

  // Optional fields.
  $signature->field_sig_state = text_field();
  $signature->field_sig_zip_code = text_field();
  $signature->field_sig_country = text_field();
  $signature->field_sig_postal_code = text_field();

  // Save the signature to the database.
  return entity_save('signature', $signature);
}

function generate_placeholders($nid, $count, $offset = 0) {
  for ($i = 0; $i < $count; $i++) {
    $email = sprintf('placeholder.%08u@takepart.com', $i + $offset);
    save_signature($nid, $email, 'John', 'Doe');
  }
}

$nid = 27667;
//generate_placeholders($nid, 100, 0);
generate_placeholders($nid, 1000, 100);
