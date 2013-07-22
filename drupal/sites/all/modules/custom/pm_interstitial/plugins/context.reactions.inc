<?php

/**
 * Expose interstitial provider as a context reaction.
 */
class InterstitialProviderReaction extends context_reaction {

  public static function get_exclusions($cmpid) {

    $exclusions = array();

    // Check if the cmpid starts with an email prefix.
    $email_prefixes = pm_split(variable_get('pm_interstitial_email_cmpids', ''),
      "\n", array("\r\n", "\r"));
    foreach ($email_prefixes as $prefix) {
      if (strncasecmp($prefix, $cmpid, strlen($prefix)) === 0) {
        $exclusions[] = 'email';
      }
    }

    // Check if the cmpid starts with a social prefix.
    $social_prefixes = pm_split(variable_get('pm_interstitial_social_cmpids', ''),
      "\n", array("\r\n", "\r"));
    foreach ($social_prefixes as $prefix) {
      if (strncasecmp($prefix, $cmpid, strlen($prefix)) === 0) {
        $exclusions[] = 'social';
      }
    }

    return $exclusions;
  }

  public static function get_interstitial($exclude) {

    // Get the list of email interstitials.
    $email_list = variable_get('pm_interstitial_email_interstitials', '');
    $email_interstitials = pm_split($email_list, "\n", array("\r\n", "\r"));

    // Get the list of social interstitials.
    $social_list = variable_get('pm_interstitial_social_interstitials', '');
    $social_interstitials = pm_split($social_list, "\n", array("\r\n", "\r"));

    // Build a master list of all available interstitials.
    $interstitials = array(
      'email' => $email_interstitials,
      'social' => $social_interstitials,
    );
    $available = array();
    foreach ($interstitials as $group => $list) {
      if (!in_array($group, $exclude)) {
        $available += $list;
      }
    }

    // Randomly select one of the available interstitials.
    if (count($available) > 0) {
      $selection = rand(0, count($available) - 1);
      return $available[$selection];
    }

    // No interstitial to show.
    return FALSE;
  }

  /**
   * Convert the interstitial provider path to a URL.
   *
   * Converts the interstitial provider path to a URL, adding any needed
   * exclusions based on the referring campaign id (cmpid) if one is present.
   */
  public static function provider_url($path, $active, $cmpid = NULL) {

    // The provider only need to be parameterized on pages where the
    // interstitial is active.
    $query = array();
    if ($active) {
      $query['active'] = 'true';
      if (isset($cmpid)) {
        $query['cmpid'] = $cmpid;
      }
    }

    // Build and return the provider path.
    $url_options = array();
    if (count($query) > 0) {
      $url_options['query'] = $query;
    }
    return url($path, $url_options);
  }

  public function options_form($context) {

    $values = $this->fetch_from_context($context);

    // The reaction needs the path to the interstitial provider.
    $form = array(
      'path' => array(
        '#type' => 'value',
        '#value' => 'interstitials',
      ),
      'comment' => array(
        '#type' => 'markup',
        '#markup' => '<p>' . t('Adds the interstitial provider URL as an additional body data attribute (<strong>data-interstitial-provider</strong>).') . '</p>',
      ),
    );
    return $form;
  }

  public function execute(&$vars, $active = FALSE, $cmpid = NULL) {

    $contexts = $this->get_contexts();
    if (count($contexts) > 0) {
      foreach ($contexts as $k => $v) {

        // Get the provider path.
        $path = $v->reactions[$this->plugin]['path'];
        $path = empty($path) ? 'interstitials' : $path;

        // Build the provider url.
        $url = self::provider_url($path, $active, $cmpid);

        // Add the attribute to the body tag.
        $vars['attributes_array']['data-interstitial-provider'] = $url;
      }
    }
  }
}

/**
 * Expose interstitial provider as a context reaction.
 */
class InterstitialActivationReaction extends context_reaction {

  public function options_form($context) {

    $values = $this->fetch_from_context($context);

    // The reaction needs the enabled state of the interstitial.
    $form = array(
      'active' => array(
        '#title' => t('Enabled'),
        '#description' => t('Enable interstitials. Adds the interstitial enabled state as a class (<strong>interstitial-active</strong>) on the body tag.'),
        '#type' => 'checkbox',
        '#default_value' => isset($values['active']) ? $values['active'] : TRUE,
      ),
    );
    return $form;
  }

  public function execute(&$vars) {
    $active = FALSE;
    $contexts = $this->get_contexts();
    if (count($contexts) > 0) {

      // Let any of the contexts active the interstitial.
      foreach ($contexts as $k => $v) {
        $active = $active || !empty($v->reactions[$this->plugin]['active']);
      }

      // Add the class to the body tag.
      if ($active) {
        $vars['classes_array'][] = 'interstitial-active';
      }
    }
    return $active;
  }
}
