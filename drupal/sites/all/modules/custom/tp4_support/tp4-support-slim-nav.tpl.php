<div class="menu-toggle">
</div>
<div class="left">
  <div class="logo">
    <?php $logo = '<img src="'. $logo. '">'; ?>
    <?php 
    global $base_url;
    if (arg(0) === 'iframes') {
        $link_url = str_replace('https://', 'http://', $base_url);
    } else {
        $link_url = $base_url;
    }
    print l($logo, $link_url, array('html' => true)); 
    ?>
  </div>
  <nav id="main-menu">
    <?php 
    if (arg(0) === 'iframes') {
      print str_replace('https://', 'http://', $slimnav); 
    } else {
      print $slimnav;
    }
    ?>
  </nav>
</div>
<div class="right">
  <div class="follow-us">
    <?php print drupal_render(menu_tree('menu-social-header-follow')); ?>
  </div>
  <div class="user-menu">
    <ul>
      <?php 
      $sign = implode($user_links);
      if (arg(0) === 'iframes') {
          print str_replace('https://', 'http://', $sign);
      }
      else {
          print $sign;
      }
      ?>
    </ul>
  </div>
  <?php if(arg(0) != 'iframes'): ?>
  <div class="search">
    <div class="search-toggle"></div>
    <?php print drupal_render(module_invoke('search_api_page', 'block_view', '2')); ?>
  </div>
  <?php endif; ?>
</div>
<div class="clearfix"></div>