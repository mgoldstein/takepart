<?php


function petition_add_field_instance($info) {
  $field = field_info_field($info['instance']['field_name']);
  if (empty($field)) {
    field_create_field($info['field']);
  }
  $instance = field_info_instance($info['instance']['entity_type'],
    $info['instance']['field_name'], $info['instance']['bundle']);
  if (empty($instance)) {
    field_create_instance($info['instance']);
  }
}

function petition_add_signature_email($bundle) {
  $info = array(
    'field' => array(
      'field_name' => 'signature_email',
      'type' => 'text',
      'entity_types' => array('petition_signature'),
    ),
    'instance' => array(
      'field_name' => 'signature_email',
      'entity_type' => 'petition_signature',
      'bundle' => $bundle,
      'label' => t('E-mail'),
      'required' => TRUE,
      'default_value_function' => 'petition_signature_field_default_value',
      'settings' => array(
        'text_processing' => 0,
      ),
      'widget' => array(
        'type' => 'text_textfield',
        'settings' => array(
          'size' => 16,
        ),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'text_default',
          'settings' => array(),
        ),
      ),
    ),
  );
  petition_add_field_instance($info);
}

function petition_add_signature_first_name($bundle) {
  $info = array(
    'field' => array(
      'field_name' => 'signature_first_name',
      'type' => 'text',
      'entity_types' => array('petition_signature'),
    ),
    'instance' => array(
      'field_name' => 'signature_first_name',
      'entity_type' => 'petition_signature',
      'bundle' => $bundle,
      'label' => t('First Name'),
      'required' => TRUE,
      //'default_value_function' => 'petition_signature_field_default_value',
      'settings' => array(
        'text_processing' => 0,
      ),
      'widget' => array(
        'type' => 'text_textfield',
        'settings' => array(
          'size' => 8,
        ),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'text_default',
          'settings' => array(),
        ),
      ),
    ),
  );
  petition_add_field_instance($info);
}

function petition_add_signature_last_name($bundle) {
  $info = array(
    'field' => array(
      'field_name' => 'signature_last_name',
      'type' => 'text',
      'entity_types' => array('petition_signature'),
    ),
    'instance' => array(
      'field_name' => 'signature_last_name',
      'entity_type' => 'petition_signature',
      'bundle' => $bundle,
      'label' => t('Last Name'),
      //'default_value_function' => 'petition_signature_field_default_value',
      'required' => TRUE,
      'settings' => array(
        'text_processing' => 0,
      ),
      'widget' => array(
        'type' => 'text_textfield',
        'settings' => array(
          'size' => 8,
        ),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'text_default',
          'settings' => array(),
        ),
      ),
    ),
  );
  petition_add_field_instance($info);
}

function petition_add_signature_public_display($bundle) {
  $info = array(
    'field' => array(
      'field_name' => 'signature_public_display',
      'type' => 'list_boolean',
      'settings' => array(
        'allowed_values' => array(
          '0' => '0',
          '1' => '1',
        ),
      ),
      'entity_types' => array('petition_signature'),
    ),
    'instance' => array(
      'field_name' => 'signature_public_display',
      'entity_type' => 'petition_signature',
      'bundle' => $bundle,
      'label' => t('Display my signature.'),
      'default_value' => '1',
      'settings' => array(),
      'widget' => array(
        'type' => 'options_onoff',
        'settings' => array(
          'display_label' => 1,
        ),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'list_default',
          'settings' => array(),
        ),
      ),
    ),
  );
  petition_add_field_instance($info);
}

function petition_add_signature_comment($bundle) {
  $info = array(
    'field' => array(
      'field_name' => 'signature_comment',
      'type' => 'text_long',
      'entity_types' => array('petition_signature'),
    ),
    'instance' => array(
      'field_name' => 'signature_comment',
      'entity_type' => 'petition_signature',
      'bundle' => $bundle,
      'label' => t('Your reason for signing (optional)'),
      'settings' => array(
        'text_processing' => 0,
      ),
      'widget' => array(
        'type' => 'text_textarea',
        'settings' => array(
          'rows' => 5,
        ),
      ),
      'display' => array(
        'default' => array(
          'label' => 'above',
          'type' => 'text_default',
          'settings' => array(),
        ),
      ),
    ),
  );
  petition_add_field_instance($info);
}

function create_water_bill_of_rights_type($type) {
  $values = array(
    'type' => $type,
    'label' => t('Water Bill of Rights Petition'),
  );
  $petition_type = petition_type_create($values);
  $status = $petition_type->save();
  if ($status == SAVED_NEW) {
    petition_add_signature_email($petition_type->signatureType());
    petition_add_signature_first_name($petition_type->signatureType());
    petition_add_signature_last_name($petition_type->signatureType());
    petition_add_signature_comment($petition_type->signatureType());
    petition_add_signature_public_display($petition_type->signatureType());
  } 
}

function create_water_bill_of_rights_petition($type) {
  $values = array(
    'type' => $type,
    'name' => 'Water Bill of Rights',
    'goal' => 10000,
  );
  $controller = entity_get_controller('petition');
  $petition = $controller->create($values);
  $petition->save();
  return $petition;
}

function migrate_signatures($petition) {
  $query = db_select('takepart_petition_signature','s')
    ->fields('s');
  $results = $query->execute();
  $count = 0;
  while ($result = $results->fetchAssoc()) {
    print ".";
    $values = array(
      'created' => $result['created'],
    );
    $signature = $petition->createSignature($values);
    $lang = $signature->language;
    $signature->signature_email[$lang][0]['value'] = $result['mail'];
    $signature->signature_first_name[$lang][0]['value'] = $result['first_name'];
    $signature->signature_last_name[$lang][0]['value'] = $result['last_name'];
    $signature->signature_public_display[$lang][0]['value'] = 1;
    $signature->signature_comment[$lang][0]['value'] = $result['comment'];
    $signature->save();
    $count += 1;
  }
  print "\n";
  return $count;
}

if (module_exists('takepart_petition')) {
  $type = 'water_bill_of_rights';
  create_water_bill_of_rights_type($type);
  $petition = create_water_bill_of_rights_petition($type);
  $count = migrate_signatures($petition);
  module_disable(array('takepart_petition'), FALSE);
  print "$count signature(s) migrated\n";
}
else {
  print 'Nothing to migrate\n';
}

?>

