<?php
/**
 * Filter by file type
 */
class views_handler_filter_file_entity_type extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('File types');
      $types = file_info_file_types();
      foreach ($types as $type => $info) {
        $options[$type] = t($info['label']);
      }
      $this->value_options = $options;
    }
  }
}
