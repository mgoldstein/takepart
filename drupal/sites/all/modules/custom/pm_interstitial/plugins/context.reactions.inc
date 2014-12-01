<?php

/**
 * Expose interstitial referer type as a context reaction.
 */
class InterstitialReaction extends context_reaction {

  public static function get_referer_types($cmpid) {

    $types = array();

    // Check if the cmpid starts with an email prefix.
    $email_prefixes = pm_split(variable_get('pm_interstitial_email_cmpids', ''),
      "\n", array("\r\n", "\r"));
    foreach ($email_prefixes as $prefix) {
      if (strncasecmp($prefix, $cmpid, strlen($prefix)) === 0) {
        $types[] = 'email';
      }
    }

    // Check if the cmpid starts with a social prefix.
    $social_prefixes = pm_split(variable_get('pm_interstitial_social_cmpids', ''),
      "\n", array("\r\n", "\r"));
    foreach ($social_prefixes as $prefix) {
      if (strncasecmp($prefix, $cmpid, strlen($prefix)) === 0) {
        $types[] = 'social';
      }
    }

    return $types;
  }

  public static function get_interstitial($type) {

    // Get the list of interstitials.
    $list = variable_get("pm_interstitial_{$type}_interstitials", '');
    $interstitials = pm_split($list, "\n", array("\r\n", "\r"));

    // Randomly select one of the available interstitials.
    if (count($interstitials) > 0) {
      $selection = rand(0, 1);
      return $interstitials[$selection];
    }

    // No interstitial to show.
    return FALSE;
  }

  public function options_form($context) {
    $form = array(
      'actve' => array(
        '#type' => 'value',
        '#value' => TRUE,
      ),
      'comment' => array(
        '#type' => 'markup',
        '#markup' => '<p>' . t('Adds the interstitial referer type(s) as an additional body data attribute (<strong>data-interstitial-referer</strong>).') . '</p>',
      ),
    );
    return $form;
  }

  public function execute(&$vars, $cmpid = '') {
    $contexts = $this->get_contexts();
    if (count($contexts) > 0) {
      foreach ($contexts as $k => $v) {
        // Add the referer type attribute to the body tag.
        $types = self::get_referer_types($cmpid);
        $vars['attributes_array']['data-interstitial-referer']
          = implode(',', $types);
      }
    }
  }
}
