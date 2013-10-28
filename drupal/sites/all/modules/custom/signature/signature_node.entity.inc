<?php
/**
 * @file
 * Signature node settings entity.
 */

/**
 * SignatureNode Entity.
 */
class SignatureNode extends Entity {

  /**
   * Overrides Entity::__construct().
   */
  public function __construct($values = array(),
    $entity_type = 'signature_node') {
    parent::__construct($values, $entity_type);
  }

  /**
   * Overrides Entity::defaultUri().
   */
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

  /**
   * Implements EntityApiControllerInterface.
   */
  public function create(array $values = array()) {
    $values += array(
      'nid' => '',
      'type' => '',
      'bsd_form' => 0,
      'pm_signup_endpoint_id' => 0,
    );
    return parent::create($values);
  }

  /**
   * Implements EntityApiControllerInterface.
   */
  protected function buildQuery($ids, $conditions = array(),
    $revision_id = FALSE) {
    global $user;
    $email = empty($user->mail) ? '' : $user->mail;
    $count_query = db_select('signature', 'sc');
    $count_query->addField('sc', 'nid', 'nid');
    $count_query->addExpression('COUNT(sc.nid)', 'count');
    $count_query->groupBy('sc.nid');
    $signed_query = db_select('signature', 'ss');
    $signed_query->addField('ss', 'nid', 'nid');
    $signed_query->addExpression('COUNT(ss.nid)', 'signed');
    $signed_query->condition('ss.email', $email, '=');
    $signed_query->groupBy('ss.nid');
    $query = parent::buildQuery($ids, $conditions, $revision_id);
    $query->leftJoin('node', 'n', 'base.nid = n.nid');
    $query->addField('n', 'title', 'title');
    $query->addField('n', 'type', 'node_type');
    $query->leftJoin($count_query, 'c', 'base.nid = c.nid');
    $query->addField('c', 'count', 'count');
    $query->leftJoin($signed_query, 's', 'base.nid = s.nid');
    $query->addField('s', 'signed', 'signed');
    return $query;
  }

  /**
   * Implements EntityApiControllerInterface.
   */
  protected function attachLoad(&$queried_entities, $revision_id = FALSE) {
    foreach ($queried_entities as $key => $entity) {
      if (!isset($entity->count)) {
        $entity->count = 0;
      }
      if (!isset($entity->signed)) {
        $entity->signed = 0;
      }
      if (!isset($entity->title)) {
        $entity->title = t('Settings for node @nid', array(
          '@nid' => $entity->nid,
        ));
      }
      if (!isset($entity->node_type)) {
        $entity->node_type = '';
      }
      $queried_entities[$key] = $entity;
    }
    parent::attachLoad($queried_entities, $revision_id);
  }
}
