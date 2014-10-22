<div class="tp-slim-nav-wrapper">
  <div class="menu-toggle"></div>
  <div class="left">
    <div class="logo">
      <?php print $logo; ?>
    </div>
    <div class="megamenu-wrapper">
      <nav id="megamenu" class="tp-slim-nav">
        <?php print $slimnav; ?>
      </nav>
    </div>
    <?php
      print render($left_info);
    ?>
  </div>
  <div class="right">
    <div class="follow-us">
      <?php if(!empty($social_menu)): ?>
        <div class="title">Follow</br>Pivot</div>
        <?php print render($social_menu); ?>
      <?php endif; ?>
    </div>
    <?php
      print render($right_info);
    ?>
    <?php print render($search); ?>
  </div>
  <div class="clearfix"></div>
</div>