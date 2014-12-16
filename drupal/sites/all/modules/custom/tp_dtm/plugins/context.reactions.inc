<?php

/**
 * Class for tp_dtm context reaction extension
 */
class tpShowDtm extends context_reaction {

  public function executePageTop() {
    /* get the dtm_src set in the settings file */
    $dtm_src = variable_get('dtm_script_src');
    if(!empty($dtm_src)){
      drupal_add_js($dtm_src, 'external');
    }
  }
  public function executePageBottom($page) {
    /* get the dtm_src set in the settings file */
    $page['page_bottom'][] = array(
      '#weight' => 25,
      '#markup' => '<script type="text/javascript">_satellite.pageBottom();</script>',
    );
    return $page;
  }
}
