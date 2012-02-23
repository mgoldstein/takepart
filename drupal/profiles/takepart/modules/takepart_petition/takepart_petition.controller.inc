<?php

/**
 * Petition Form class.
 */
class TakePartPetitionForm extends Entity {

  public $name;
  public $label;
  public $petition_form_id;
  public $goal;
  public $mail_field_id;
  public $last_name_field_id;
  public $first_name_field_id;
  public $zip_code_field_id;
  public $comment_field_id;
  public $source_ngo_field_id;
  public $ngo_opt_in_field_id;
  public $campaign_opt_in_field_id;
  public $campaign_signup_form_id;
  public $campaign_mail_field_id;

  public function __construct($values = array()) {
    parent::__construct($values, 'takepart_petition_form');
  }

  function isLocked() {
    return isset($this->status) && empty($this->is_new) && (($this->status & ENTITY_IN_CODE) || ($this->status & ENTITY_FIXED));
  }
}

class TakePartPetitionFormController extends EntityAPIControllerExportable {
   public function create(array $values = array()) {
    $values += array(
      'name' => '',
      'label' => '',
      'petition_form_id' => 0,
      'goal' => 100000,
      'mail_field_id' => 0,
      'last_name_field_id' => 0,
      'first_name_field_id' => 0,
      'zip_code_field_id' => 0,
      'comment_field_id' => 0,
      'source_ngo_field_id' => 0,
      'ngo_opt_in_field_id' => 0,
      'campaign_opt_in_field_id' => 0,
      'campaign_signup_form_id' => 0,
      'campaign_mail_field_id' => 0,
    );
    return parent::create($values);
  }
}

/**
 * UI controller for Petition forms.
 */
class TakePartPetitionFormUIController extends EntityDefaultUIController {
  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage Petition Forms.';
    return $items;
  }
}


/**
 * Petition signature class.
 */
class TakePartPetitionSignature extends Entity {

  public $petition_form;
  public $mail;
  public $last_name;
  public $first_name;
  public $comment;
  public $shown;
  public $created;

  public function __construct($values = array()) {
    parent::__construct($values, 'takepart_petition_signature');
  }
}

class TakePartPetitionSignatureController extends EntityAPIController {

  public function create(array $values = array()) {
    global $user;
    $values += array(
      'mail' => $user->mail,
      'last_name' => '',
      'first_name' => '',
      'comment' => '',
      'shown' => 1,
      'created' => REQUEST_TIME,
    );
    return parent::create($values);
  }
}


/**
 * Petition class.
 */
class TakePartPetitionNGO extends Entity {

  public $label;
  public $token;

  public function __construct($values = array()) {
    parent::__construct($values, 'takepart_petition_ngo');
  }

  function isLocked() {
    return isset($this->status) && empty($this->is_new) && (($this->status & ENTITY_IN_CODE) || ($this->status & ENTITY_FIXED));
  }
}

/**
 * UI controller for Petition.
 */
class TakePartPetitionNGOUIController extends EntityDefaultUIController {
  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage Petition NGOs.';
    return $items;
  }
}
