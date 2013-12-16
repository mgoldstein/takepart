<?php
/*
 * implements hook_FORMID_alter()
 *
 * we are limiting the types of nodes that can be embed and also
 * telling the user that.
 */
function takepart_custom_form_embeddable_embed_form_alter(&$form, &$form_state) {
  if(isset($form['wrapper']['nid'])) {
    $form['wrapper']['nid']['#autocomplete_path'] = 'entity-autocomplete/bundle/node/action+openpublish_video+openpublish_photo_gallery+petition_action+pledge_action';
    $form['wrapper']['nid']['#description'] = 'Limited to Videos Galleries and Actions';
    $form['wrapper']['view_mode']['#default_value'] = 'embed';
  }
}

/*
 * implements hook_info_alter()
 *
 * we are adding a embed view mode
 */
function takepart_custom_entity_info_alter(&$entity_info) {
  $entity_info['node']['view modes']['embed'] = array('label' => 'Embedded (Action Link)', 'custom settings' => FALSE);
}
