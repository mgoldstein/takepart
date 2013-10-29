<div class="logo">  
  <img src="<?php print $logo; ?>">
</div>
<div class="follow-us">
  <div class="text">Follow Us</div><?php print drupal_render(menu_tree('menu-social-header-follow')); ?>
</div>
<div class="user-menu">
  <ul>
    <?php print implode($user_links); ?>
  </ul>
</div>
<div class="search">
  <?php print drupal_render(module_invoke('search_api_page', 'block_view', '2')); ?>
</div>
<nav>
  <ul>
    <li class="news">In the News</li>
    <li class="lifestyle">Lifestyle</li>
    <li class="features">Features & Columns</li>
    <li class="action">Take Action</li>
    <li class="tpl">TakePart Live</li>
  </ul>
</nav>