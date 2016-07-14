<style>
  nav#cic-menu .cic-menu-inner .content-menu li.is-leaf a.current-node {
    color: <?php print $camp_color; ?>;
  }
</style>

<span class="icon i-close-x"></span>
    <div class = "first-col col-sm-4">
      <h6 class="col-title desktop">about the issue</h6>
      <div class = "about-campaign">
        <h3 class="campaign-title"><?php print $camp_name; ?></h3>
        <p class="campaign-description"><?php print $camp_description; ?></p>
      </div>
      <?php print l('Home', $camp_url , array('attributes' => array('class' => array('camp-home-link mobile')))); ?>
      <div class = "campaign-menu desktop">
        <h6 class="col-title desktop">inside the big issue</h6>
        <div class= "campaign-menu-inner desktop">
          <?php print $camp_menu; ?>
        </div>
      </div>
    </div>
    <div class = "second-col col-sm-4">
      <h6 class="col-title">Stories</h6>
      <div class= "content-menu">
        <?php print $camp_content_menu; ?>
      </div>
      <div class= "campaign-menu mobile">
        <?php print $camp_menu; ?>
      </div>
    </div>
    <div class= "third-col col-sm-4">
      <img src="http://s3.amazonaws.com/tab_assets/shared_assets/images/tp_logo_black.svg" class="logo-transparent">
      <div class = "about-tp">
        <?php print $about_tp; ?><br>
        <a href="/" class="hp-link">Visit takepart.com</a>
        <p class = "follow">FOLLOW US</p>
        <?php print $social_menu; ?>
      </div>
    </div>
