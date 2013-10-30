<?php

class NewsletterCampaignSignup extends SimpleOptInSignup {}


class NewsletterCampaignSignupEndpoint extends SimpleOptInSignupEndpoint {

  public static function namedEnpoints() {
    return db_select('pm_signup_endpoint', 'ep')
      ->fields('ep', array('name', 'label'))
      ->condition('type', 'NewsletterCampaignSignupEndpoint')
      ->isNotNull('name')
      ->execute()
      ->fetchAllKeyed();
  }
}
