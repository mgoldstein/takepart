<?php

/**
 * SignatureNode Entity.
 */
class SignatureNode extends Entity {

  public function __construct($values = array(),
    $entity_type = 'signature_node') {
    parent::__construct($values, $entity_type);
  }

  protected function defaultUri() {
    if (!empty($this->nid)) {
      return array(
        'path' => 'node/' . $this->nid,
      );
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
      'end_date' => time() + 365 * 24 * 60 * 60,
      'heading' => 'Sign This Petition',
      'sign_label' => 'Sign Petition',
      'newsletter_opt_ins' => array(),
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
    $count_query = db_select('signature', 'sc');
    $count_query->addField('sc', 'nid', 'nid');
    $count_query->addExpression('COUNT(sc.nid)', 'count');
    $count_query->groupBy('sc.nid');
    $query = parent::buildQuery($ids, $conditions, $revision_id);
    $query->leftJoin('node', 'n', 'base.nid = n.nid');
    $query->addField('n', 'title', 'title');
    $query->leftJoin($count_query, 'c', 'base.nid = c.nid');
    $query->addField('c', 'count', 'count');
    return $query;
  }

  protected function attachLoad(&$queried_entities, $revision_id = FALSE) {
    foreach ($queried_entities as $key => $entity) {
      if (!isset($entity->count)) {
        $entity->count = 0;
      }
      if (!isset($entity->title)) {
        $entity->title = t('Settings for node @nid', array(
          '@nid' => $entity->nid,
        ));
      }
      $queried_entities[$key] = $entity;
    }
    parent::attachLoad($queried_entities, $revision_id);
  }
}
