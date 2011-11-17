<?php
/**
 * Argument handler to accept a file type.
 */
class views_handler_argument_file_entity_type extends views_handler_argument_string {

  function file_type($type) {
    $output = file_info_file_types($type);
    if (empty($output)) {
      $output['label'] = t('Unknown file type');
    }
    return check_plain($output['label']);
  }

  /**
   * Override for specific title lookups.
   */
  function title_query() {
    $title = array();
    foreach($this->value as $value) {
      $title[] = $this->file_type($value);
    }
    return $title;
  }

  function summary_name($data) {
    $data->{$this->name_alias} = $this->file_type($data->{$this->name_alias});
    return $this->case_transform(parent::summary_name($data), 'case');
  }
}
