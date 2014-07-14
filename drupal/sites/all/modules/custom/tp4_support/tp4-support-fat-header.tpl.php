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
	<div class="user-menu-mobile"><div class="tpsLogin"></div></div>
  <div class="search-toggle"></div>
  <?php print drupal_render(module_invoke('search_api_page', 'block_view', '2')); ?>
</div>
<nav id="megamenu">
  <?php print $megamenu; ?>
</nav>
