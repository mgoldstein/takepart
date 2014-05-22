<?php
/**
 * @file
 * Featured Campaigns bean plugin.
 */

class FeaturedCampaignsBean extends BeanPlugin {
  /**
   * Declares default block settings.
   */
  public function values() {
    $values = array(
      'campaigns_cta' => array(
        'value' => '',
        'format' => filter_default_format(),
      ),
    );

    return array_merge(parent::values(), $values);
  }

  /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {
    $form = array();
    $form['campaigns_cta'] = array(
      '#type' => 'text_format',
      '#default_value' => $bean->data['campaigns_cta']['value'],
      '#format' => $bean->data['campaigns_cta']['format'],
      '#title' => t('Call To Action'),
      '#description' => t('Text for below the promos'),
    );
    return $form;
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    $content['bean']['campaigns-module']['cta'] = array(
      '#markup' => check_markup($bean->campaigns_cta['value'], $bean->campaigns_cta['format']),
      '#weight' => 10,
      '#prefix'=> '<div class="cta">',
      '#suffix'=> '</div>',
    );
    return $content;
  }
}
