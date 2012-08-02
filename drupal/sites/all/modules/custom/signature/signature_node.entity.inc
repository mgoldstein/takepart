<?php

class SignatureNode extends Entity {

  public function __construct($values = array(),
    $entity_type = 'signature_node') {
    parent::__construct($values, $entity_type);
  }
  
  protected function defaultLabel() {
    if (!empty($this->nid)) {
      return entity_label('node', $this->nid);  
    }
    return t('Settings for node @nid', array('@nid' => $this->nid));
  }
  
  protected function defaultUri() {
    if (!empty($this->nid)) {
      return entity_uri('node', $this->nid);  
    }
    return NULL;
  }
}

class SignatureNodeController extends EntityAPIController {

  public function create(array $values = array()) {
    $values += array(
      'nid' => '',
      'type' => '',
      'goal' => 100000,
      'bsd_form' => 0,
      'limit_to_dates' => FALSE,
      'start_date' => time(),
      'end_date' => time() + 365*24*60*60,
      'heading' => 'Sign This Petition',
      'sign_label' => 'Sign Petition',
      'newsletter_group' => '',
      'newsletter_label' => '',
      'restrictions' => '',
      'terms_of_use' => "By signing, you accept TakePart's "
        . '<a href="/terms-of-use" target="_blank">Terms of Use</a>.',
      'display_disclaimer' => implode(' ', array(
        'You may choose not to display your name on this website,',
        'but TakePart will include your name,',
        'e-mail address and zip code in the petition,',
        'which may be made public and presented to lawmakers.',
      )),
    );
    return parent::create($values);
  }
  
  protected function buildQuery($ids, $conditions = array(), $revision_id = FALSE) {
    $countQuery = db_select('signature', 'sc');
    $countQuery->addField('sc', 'nid', 'nid');
    $countQuery->addExpression('COUNT(sc.nid)', 'count');
    $countQuery->groupBy('sc.nid');
    $query = parent::buildQuery($ids, $conditions, $revision_id);
    $query->leftJoin($countQuery, 'c', 'base.nid = c.nid');
    $query->addField('c', 'count', 'count');
    return $query;
  }
  
  protected function attachLoad(&$queried_entities, $revision_id = FALSE) {
    foreach ($queried_entities as $key => $entity) {
      if (!isset($entity->count)) {
        $entity->count = 0;
      }
      $queried_entities[$key] = $entity;
    }
    parent::attachLoad($queried_entities, $revision_id);
  }
}
