<?php
/**
 * @file
 * newsletter_campaign_signups.features.pm_signup_endpoint.inc
 */

/**
 * Implements hook_pm_signup_endpoint_defaults().
 */
function newsletter_campaign_signups_pm_signup_endpoint_defaults() {
  $endpoints = array();
  $endpoints[] = array(
    'type' => 'NewsletterCampaignSignupEndpoint',
    'name' => 'can_email_signup',
    'label' => 'CAN Email Signup',
    'configuration' => array(),
    'plugins' => array(
      'bluestatedigital.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'form-id' => 140,
          'email-field-id' => 2784,
        ),
      ),
      'bluehornet.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'segments' => array(
            0 => '1008407',
          ),
          'fields' => array(
            252906 => 'Webform',
            253159 => 'CAN',
          ),
          'send-welcome' => TRUE,
        ),
      ),
    ),
  );
  $endpoints[] = array(
    'type' => 'NewsletterCampaignSignupEndpoint',
    'name' => 'food_inc',
    'label' => 'Food, Inc.',
    'configuration' => array(),
    'plugins' => array(
      'bluestatedigital.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'form-id' => 4,
          'email-field-id' => 38,
        ),
      ),
      'bluehornet.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'account' => 'takepart',
          'segments' => array(
            0 => '1008360',
          ),
          'fields' => array(
            252906 => 'Webform',
            253159 => 'FOODINC',
          ),
          'send-welcome' => TRUE,
        ),
      ),
    ),
  );
  $endpoints[] = array(
    'type' => 'NewsletterCampaignSignupEndpoint',
    'name' => 'food_inc_awards',
    'label' => 'Food, Inc. Awards',
    'configuration' => array(),
    'plugins' => array(
      'bluehornet.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'account' => 'takepart',
          'segments' => array(
            0 => '1008360',
            1 => '1022166',
          ),
          'fields' => array(
            252906 => 'Food Inc Awards',
            253159 => 'FOODINC',
          ),
          'send-welcome' => TRUE,
        ),
      ),
    ),
  );
  $endpoints[] = array(
    'type' => 'NewsletterCampaignSignupEndpoint',
    'name' => 'give_150',
    'label' => 'Give 150',
    'configuration' => array(),
    'plugins' => array(
      'bluestatedigital.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'form-id' => 9,
          'email-field-id' => 108,
        ),
      ),
      'bluehornet.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'account' => 'takepart',
          'segments' => array(
            0 => '1009255',
          ),
          'fields' => array(
            252906 => 'Webform',
          ),
          'send-welcome' => FALSE,
        ),
      ),
    ),
  );
  $endpoints[] = array(
    'type' => 'NewsletterCampaignSignupEndpoint',
    'name' => 'intel_girls_education_campaign',
    'label' => 'Intel Girl\'s Education Campaign',
    'configuration' => array(),
    'plugins' => array(
      'bluestatedigital.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'form-id' => 54,
          'email-field-id' => 916,
          'phone-field-id' => 927,
        ),
      ),
      'waterfallapi.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'us-flow-id' => '51106a5a0cf21faa046d7edf',
        ),
      ),
      'bluehornet.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'account' => 'takepart',
          'segments' => array(
            0 => '1008366',
            1 => '1008403',
          ),
          'fields' => array(
            252906 => 'Webform',
            253159 => 'INTEL',
          ),
          'send-welcome' => TRUE,
        ),
      ),
    ),
  );
  $endpoints[] = array(
    'type' => 'NewsletterCampaignSignupEndpoint',
    'name' => 'komen_email_capture',
    'label' => 'Komen Email Capture',
    'configuration' => array(),
    'plugins' => array(
      'bluestatedigital.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'form-id' => 122,
          'email-field-id' => 2421,
        ),
      ),
      'bluehornet.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'account' => 'takepart',
          'segments' => array(
            0 => '1009256',
          ),
          'fields' => array(
            252906 => 'Webform',
          ),
          'send-welcome' => FALSE,
        ),
      ),
    ),
  );
  $endpoints[] = array(
    'type' => 'NewsletterCampaignSignupEndpoint',
    'name' => 'newsletter_interstitial',
    'label' => 'Newsletter Interstitial Signup',
    'configuration' => array(),
    'plugins' => array(
      'bluestatedigital.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'form-id' => 5,
          'email-field-id' => 52,
        ),
      ),
      'bluehornet.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'segments' => array(
            0 => '1008359',
            1 => '1008357',
            2 => '1008358',
          ),
          'fields' => array(
            252906 => 'Marketing Interstitial',
            253159 => 'NEWS',
          ),
          'send-welcome' => TRUE,
        ),
      ),
    ),
  );
  $endpoints[] = array(
    'type' => 'NewsletterCampaignSignupEndpoint',
    'name' => 'place_at_the_table',
    'label' => 'A Place at the Table',
    'configuration' => array(),
    'plugins' => array(
      'bluestatedigital.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'form-id' => 35,
          'email-field-id' => 586,
        ),
      ),
      'bluehornet.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'account' => 'takepart',
          'segments' => array(
            0 => '1008364',
          ),
          'fields' => array(
            252906 => 'Webform',
            253159 => 'APATT',
          ),
          'send-welcome' => TRUE,
        ),
      ),
    ),
  );
  $endpoints[] = array(
    'type' => 'NewsletterCampaignSignupEndpoint',
    'name' => 'takepart_education',
    'label' => 'TakePart Education',
    'configuration' => array(),
    'plugins' => array(
      'bluestatedigital.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'form-id' => 53,
          'email-field-id' => 902,
        ),
      ),
      'bluehornet.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'account' => 'takepart',
          'segments' => array(
            0 => '1008361',
          ),
          'fields' => array(
            252906 => 'Webform',
            253159 => 'WFS',
          ),
          'send-welcome' => TRUE,
        ),
      ),
    ),
  );
  $endpoints[] = array(
    'type' => 'NewsletterCampaignSignupEndpoint',
    'name' => 'takepart_environment',
    'label' => 'TakePart Environment',
    'configuration' => array(),
    'plugins' => array(
      'bluestatedigital.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'form-id' => 21,
          'email-field-id' => 316,
        ),
      ),
      'bluehornet.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'account' => 'takepart',
          'segments' => array(
            0 => '1008363',
          ),
          'fields' => array(
            252906 => 'Webform',
            253159 => 'AIT',
          ),
          'send-welcome' => TRUE,
        ),
      ),
    ),
  );
  $endpoints[] = array(
    'type' => 'NewsletterCampaignSignupEndpoint',
    'name' => 'takepart_newsletter',
    'label' => 'TakePart Newsletter',
    'configuration' => array(),
    'plugins' => array(
      'bluestatedigital.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'form-id' => 5,
          'email-field-id' => 52,
        ),
      ),
      'bluehornet.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'account' => 'takepart',
          'segments' => array(
            0 => '1008359',
            1 => '1008357',
            2 => '1008358',
          ),
          'fields' => array(
            252906 => 'Webform',
            253159 => 'NEWS',
          ),
          'send-welcome' => TRUE,
        ),
      ),
    ),
  );
  $endpoints[] = array(
    'type' => 'NewsletterCampaignSignupEndpoint',
    'name' => 'takepart_wildlife',
    'label' => 'TakePart Wildlife',
    'configuration' => array(),
    'plugins' => array(
      'bluestatedigital.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'form-id' => 40,
          'email-field-id' => 662,
        ),
      ),
      'bluehornet.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'account' => 'takepart',
          'segments' => array(
            0 => '1008362',
          ),
          'fields' => array(
            252906 => 'Webform',
            253159 => 'COVE',
          ),
          'send-welcome' => TRUE,
        ),
      ),
    ),
  );
  $endpoints[] = array(
    'type' => 'NewsletterCampaignSignupEndpoint',
    'name' => 'teach_campaign',
    'label' => 'Teach Campaign Signup',
    'configuration' => array(),
    'plugins' => array(
      'bluestatedigital.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'form-id' => 53,
          'email-field-id' => 902,
        ),
      ),
      'bluehornet.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'account' => 'takepart',
          'segments' => array(
            0 => '1008361',
          ),
          'fields' => array(
            252906 => 'Teach Webform',
            253159 => 'TEACH',
          ),
          'send-welcome' => TRUE,
        ),
      ),
    ),
  );
  $endpoints[] = array(
    'type' => 'NewsletterCampaignSignupEndpoint',
    'name' => 'chavez_campaign',
    'label' => 'Chavez Campaign Signup',
    'configuration' => array(),
    'plugins' => array(
      'bluehornet.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'account' => 'takepart',
          'segments' => array(
            0 => '1029994',
            1 => '1008360',
          ),
          'fields' => array(
            252906 => 'Webform',
            253159 => 'CHAVEZ',
          ),
          'send-welcome' => TRUE,
        ),
      ),
    ),
  );
  return $endpoints;
}
