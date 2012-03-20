<?php

/**
 * @file
 * Admin UI field handlers
 */

/**
 * This field handler aggregates operations that can be done on a contest entry
 * under a single field providing a more flexible way to present them in a view
 */
class contest_entry_handler_contest_entry_operations_field extends views_handler_field {

  function construct() {
    parent::constuct();
    $this->additional_fields['entry_id'] = 'entry_id';
    $this->additional_fields['contest_id'] = 'contest_id';
  }
  
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }
  
  function render($values) {
    $args = array(
      $this->get_value($values, 'contest_id'),
      'entry',
      $this->get_value($values, 'entry_id'),
    );
    $links = menu_contextual_links('takepart_contests', 'admin/content/contests/contest', $args);
    if (! empty($links)) {
      $variables = array(
        'links' => $links,
        'attributes' => array(
          'class' => array('links', 'inline', 'operations'),
        ),
      );
      return theme('links', $variables);
    }
  }
}

/**
 * This field handler takes care of displaying delete contest entry links as fields
 */
class contest_entry_handler_delete_link_field extends contest_entry_handler_link_field {

  function construct() {
    parent::construct();
  }
  
  function render($values) {
    if (! takepart_contests_contest_entry_access('edit')) {
      return;
    }
    $text = (! empty($this->options['text'])) ? $this->options['text'] : t('delete');
    $contest_id = $values->{$this->aliases['contest_id']};
    $entry_id = $values->{$this->aliases['entry_id']};
    return l($text, 'admin/content/contests/contest/'. $contest_id . '/entry/' . $entry_id . '/delete');
  }
}

/**
 * This field handler takes care of displaying edit contest entry links as fields
 */
class contest_entry_handler_edit_link_field extends contest_entry_handler_link_field {

  function construct() {
    parent::construct();
  }
  
  function render($values) {
    if (! takepart_contests_contest_entry_access('edit')) {
      return;
    }
    $text = (! empty($this->options['text'])) ? $this->options['text'] : t('edit');
    $contest_id = $values->{$this->aliases['contest_id']};
    $entry_id = $values->{$this->aliases['entry_id']};
    return l($text, 'admin/content/contests/contest/'. $contest_id . '/entry/' . $entry_id . '/edit');
  }
}

/**
 * This field handler takes care of displaying contest entry links as fields
 */
class contest_entry_handler_link_field extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['entry_id'] = 'entry_id';
    $this->additional_fields['contest_id'] = 'contest_id';
  }
  
  function option_definition() {
    $options = parent::option_defintion();
    $options['text'] = array('default' => '', 'translatable' => TRUE);
    return $options;
  }
  
  function options_form(&$form, &$form_state) {
    parent::options_form(form, form_state);
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }
  
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }
  
  function render($values) {
    $text = (! empty($this->options['text']) ? $this->options['text'] : t('view');
    $contest_id = $values->{$this->aliases['contest_id']};
    $entry_id = $values->{$this->aliases['entry_id']};
    return l($text, 'contest/' . $contest_id . '/entry/' . $entry_id);
  }
}

/**
 * This field handler aggregates operations that can be done on a contest
 * under a single field providing a more flexible way to present them in a view
 */
class contest_handler_contest_operations_field extends views_handler_field {

  function construct() {
    parent::constuct();
    $this->additional_fields['contest_id'] = 'contest_id';
  }
  
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }
  
  function render($values) {
    $args = array($this->get_value($values, 'contest_id'));
    $links = menu_contextual_links('takepart_contests', 'admin/content/contests/manage', $args);
    if (! empty($links)) {
      $variables = array(
        'links' => $links,
        'attributes' => array(
          'class' => array('links', 'inline', 'operations'),
        ),
      );
      return theme('links', $variables);
    }
  }
}

/**
 * This field handler takes care of displaying delete contest links as fields
 */
class contest_handler_delete_link_field extends contest_handler_link_field {

  function construct() {
    parent::construct();
  }
  
  function render($values) {
    if (! takepart_contests_contest_access('edit')) {
      return;
    }
    $text = (! empty($this->options['text'])) ? $this->options['text'] : t('delete');
    $contest_id = $values->{$this->aliases['contest_id']};
    return l($text, 'admin/content/contests/manage/' . $contest_id . '/delete');
  }
}

/**
 * This field handler takes care of displaying edit contest links as fields
 */
class contest_handler_edit_link_field extends contest_handler_link_field {

  function construct() {
    parent::construct();
  }
  
  function render($values) {
    if (! takepart_contests_contest_access('edit')) {
      return;
    }
    $text = (! empty($this->options['text'])) ? $this->options['text'] : t('edit');
    $contest_id = $values->{$this->aliases['contest_id']};
    return l($text, 'admin/content/contests/manage/' . $contest_id . '/edit');
  }
}

/**
 * This field handler takes care of displaying delete contest links as fields
 */
class contest_handler_link_field extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['contest_id'] = 'contest_id';
    $this->additional_fields['type'] = 'type';
  }
  
  function option_definition() {
    $options = parent::option_defintion();
    $options['text'] = array('default' => '', 'translatable' => TRUE);
    return $options;
  }
  
  function options_form(&$form, &$form_state) {
    parent::options_form(form, form_state);
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }
  
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }
  
  function render($values) {
    $text = (! empty($this->options['text']) ? $this->options['text'] : t('view');
    $contest_id = $values->{$this->aliases['contest_id']};
    return l($text, 'contest/' . $contest_id);
  }
}
