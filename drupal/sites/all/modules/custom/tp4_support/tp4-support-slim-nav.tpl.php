<div class="menu-toggle">
</div>
<div class="logo">
  <?php $logo = '<img src="'. $logo. '">'; ?>
  <?php global $base_url; ?>
  <?php print l($logo, $base_url, array('html' => true)); ?>
</div>
<nav id="main-menu">
  <?php print $slimnav; ?>
</nav>
<div class="follow-us">
  <?php print drupal_render(menu_tree('menu-social-header-follow')); ?>
</div>
<div class="user-menu">
  <ul>
    <?php print implode($user_links); ?>
  </ul>
</div>
<div class="search">
  <div class="search-toggle"></div>
  <?php print drupal_render(module_invoke('search_api_page', 'block_view', '2')); ?>
</div>