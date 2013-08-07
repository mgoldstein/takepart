<?php

function signature_label_to_name_mapping() {
  return array(
    'Email' => 'email',
    'First Name' => 'name.first',
    'Last Name' => 'name.last',
    'Address' => 'address.address',
    'City' => 'address.city',
    'State/Region/Province' => 'address.state.code',
    'Country' => 'address.country',
    'Zip/Postal Code' => 'address.postal-code',
    'Referrer Code' => 'partner.code',
    'action-id' => 'action.id',
    'User Custom Message' => 'action.message',
    'Public Display Opt-In' => 'action.opt-ins.display',
    'Referrer Opt-In' => 'action.opt-ins.partner',
  );
}

function signature_label_to_opt_in_mapping() {
  return array(
    'Newsletter Opt-In' => 0,
    'Newsletter Opt-In 2' => 1,
    'Newsletter Opt-In 3' => 2,
    'Newsletter Opt-In 4' => 3,
    'Newsletter Opt-In 5' => 4,
  );
}

function signature_constituent_group_configurations() {
  return array(
    // Action: Culture
    176 => array(
      'segments' => array(
        '1008359',
        '1008357',
        '1008358',
        '1008368',
        '1008386',
        '1008387',
        '1008388',
        '1008389',
        '1008390',
      ),
      'fields' => array(
        '253159' => 'NEWS',
      ),
      'send-welcome' => TRUE,
    ),
    // Action: Fair Sentencing
    211 => array(
      'segments' => array(
        '1008359',
        '1008357',
        '1008358',
        '1008368',
        '1008386',
        '1008387',
        '1008388',
        '1008389',
        '1008391',
      ),
      'fields' => array(
        '253159' => 'NEWS',
      ),
      'send-welcome' => TRUE,
    ),
    // Action: Health
    175 => array(
      'segments' => array(
        '1008359',
        '1008357',
        '1008358',
        '1008368',
        '1008386',
        '1008387',
        '1008388',
        '1008389',
        '1009346',
      ),
      'fields' => array(
        '253159' => 'NEWS',
      ),
      'send-welcome' => TRUE,
    ),
    // Action: Human Rights
    160 => array(
      'segments' => array(
        '1008359',
        '1008357',
        '1008358',
        '1008368',
        '1008386',
        '1008387',
        '1008388',
        '1008389',
        '1009347',
      ),
      'fields' => array(
        '253159' => 'NEWS',
      ),
      'send-welcome' => TRUE,
    ),
    // Action: Food
    155 => array(
      'segments' => array(
        '1008368',
        '1008386',
        '1008387',
        '1008388',
        '1008389',
        '1008392',
        '1008360',
      ),
      'fields' => array(
        '253159' => 'FOODINC',
      ),
      'send-welcome' => TRUE,
    ),
    // Action: Environment
    157 => array(
      'segments' => array(
        '1008368',
        '1008386',
        '1008387',
        '1008388',
        '1008389',
        '1008396',
        '1008363',
      ),
      'fields' => array(
        '253159' => 'AIT',
      ),
      'send-welcome' => TRUE,
    ),
    // Action: Education
    158 => array(
      'segments' => array(
        '1008368',
        '1008386',
        '1008387',
        '1008388',
        '1008389',
        '1008394',
        '1008361',
      ),
      'fields' => array(
        '253159' => 'WFS',
      ),
      'send-welcome' => TRUE,
    ),
    // Action: Wildlife
    154 => array(
      'segments' => array(
        '1008368',
        '1008386',
        '1008387',
        '1008388',
        '1008389',
        '1008395',
        '1008362',
      ),
      'fields' => array(
        '253159' => 'COVE',
      ),
      'send-welcome' => TRUE,
    ),
    // Action: APATT
    286 => array(
      'segments' => array(
        '1008368',
        '1008386',
        '1008387',
        '1008388',
        '1008389',
        '1008393',
        '1008364',
      ),
      'fields' => array(
        '253159' => 'APATT',
      ),
      'send-welcome' => TRUE,
    ),
    // TAG: Komen
    197 => array(
      'segments' => array('1008368'),
      'fields' => array(),
      'send-welcome' => FALSE,
    ),
    // Partner: Save Japan Dolphins
    90 => array(
      'segments' => array('1008368'),
      'fields' => array(),
      'send-welcome' => FALSE,
    ),
    // Partner: National Geographic
    201 => array(
      'segments' => array('1012034'),
      'fields' => array(),
      'send-welcome' => FALSE,
    ),
  );
}
