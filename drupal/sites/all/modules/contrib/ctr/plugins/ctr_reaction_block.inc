<?php

class ctr_reaction_block extends context_reaction_block {
  
  function options_form($context) {
    // Rebuild the block info cache if necessary.
    $this->get_blocks(NULL, NULL, $this->rebuild_needed());
    $this->rebuild_needed(FALSE);

    $weight_delta = $this->max_block_weight();

    $form = array(
      '#tree' => TRUE,
      '#theme' => 'context_block_form',
      'max_block_weight' => array(
        '#value' => $weight_delta,
        '#type' => 'value',
      ),
      'state' => array(
        '#type' => 'hidden',
        '#attributes' => array('class' => 'context-blockform-state'),
      ),
    );

    /**
     * Selector.
     */
    $modules = module_list();
    $form['selector'] = array(
      '#type' => 'item',
      '#tree' => TRUE,
      '#prefix' => '<div class="context-blockform-selector">',
      '#suffix' => '</div>',
    );
    foreach ($this->get_blocks() as $block) {
      $group = isset($block->context_group) ? $block->context_group : $block->module;
      if (!isset($form['selector'][$group])) {
        $form['selector'][$group] = array(
          '#type' => 'checkboxes',
          '#title' => isset($block->context_group) ? $block->context_group : $modules[$block->module],
          '#options' => array(),
        );
      }
      $form['selector'][$group]['#options'][$block->bid] = check_plain($block->info);
    }
    ksort($form['selector']);
    
    /**
     * Show all theme choose
     */
    $themes = list_themes();
    $options = array(
      '_none' => t('All themes'),
    );
    foreach ($themes as $theme) {
      $options[$theme->name] = $theme->info['name'];
    }
    $form['themes'] = array(
      '#type' => 'select',
      '#title' => t('Filter regions by theme'),
      '#description' => t('Show regions from all theme or for only theme'),
      '#options' => $options,
    );

    /**
     * Regions.
     */
    $form['blocks'] = array(
      '#tree' => TRUE,
      '#theme' => 'context_block_regions_form',
    );
    $regions = array();
    foreach ($themes as $theme_key) {
      foreach (system_region_list($theme_key->name, REGIONS_VISIBLE) as $region => $label) {
        $regions[$region][] = $theme_key->info['name'];
        $form['blocks'][$region] = array(
          '#type' => 'item',
          '#title' => $label,
          '#tree' => TRUE,
        );
        foreach ($this->get_blocks($region, $context) as $block) {
          if (!empty($block->context)) {
            $form['blocks'][$region][$block->bid] = array(
              '#value' => check_plain($block->info),
              '#weight' => $block->weight,
              '#type' => 'markup',
              '#tree' => TRUE,
              'weight' => array('#type' => 'weight', '#delta' => $weight_delta, '#default_value' => $block->weight),
            );
          }
        }
      }
    }
    
    return $form;
  }
}