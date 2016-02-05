<div class="menu-toggle">
</div>
<div class="logo">
  <?php $logo = '<img src="'. $logo. '">'; ?>
  <?php global $base_url; ?>
  <?php print l($logo, $base_url, array('html' => true)); ?>
</div>
<div class="follow-us">
  <div class="text">Follow Us</div><?php print drupal_render(menu_tree('menu-social-header-follow')); ?>
</div>
<div class="user-menu">
  <div class="tpsLogin"></div>
</div>
<div class="search">
  <div class="search-toggle"></div>
  <?php
    $block_delta = search_api_page_load_multiple();
    if(isset($block_delta['site_search']->id) && is_numeric($block_delta['site_search']->id)) {
      $b_d = $block_delta['site_search']->id;
    } else {
      $b_d = variable_get('search_api_page_block_delta', 3);
    }
    print drupal_render(module_invoke('search_api_page', 'block_view', $b_d));
  ?>
</div>
<nav id="megamenu">
  <?php print $megamenu; ?>
</nav>
