<div id="page-wrapper">
  <div id="header" class='clearfix'>
    <div id='logo'><?php print l("", "<front>")?></div>
    <div class="header-mid">
  		<div id="hot-topics-nav">
        <?php print $hottopic_nav ?>
  		</div><!--/hot topics nav-->
  		
  		<div class="text">
  		<img src="<?php print $directory?>/images/title-inspiration-to-action.gif" alt="inspiration to action">
  		</div><!--/text-->
		</div>
		<div class="header-right">
  		<div id="join-login-top">
  			<a href="#" class="join">Join TakePart</a>
  			
  			<div class="login-fb clearfix">
  					<span class="login-text">	<?php print l("Login", "user")?> or</span>
  				<span class="fb"><a href="#"><img src="images/btn-fb-1.gif"></a></span>
  			</div><!--/login-fb-->
  		</div><!--/join-login-top-->
  		
  	  <div class="clear"></div>
  			<ul id="top-follow">
  				<li class="title"><img alt="follow us" src="images/title-follow-us.gif"></li>
  				<li class="fb"><a href="#">facebook</a></li>
  				<li class="twitter"><a href="#">twitter</a></li>
  				<li class="rss"><a href="#">rss</a></li>
  			</ul><!--/top follow-->
    </div>
  </div>
  <div class="clear clearfix" id="nav-wrap">
    <?php print $top_nav ?>
  	<div id="top-search">
  	  <div class="form-item">
  	  <input type="text" class="form-text search-field" value="Search TakePart" size="15" id="edit-search-theme-form-1" name="search_theme_form">
  	  
  	  <input type="submit" class="form-submit" value="submit" id="edit-submit">
  	  </div><!--form item-->
  	</div><!--/top search-->
  </div>


  <?php if ($page['help'] || ($show_messages && $messages)): ?>
    <div id='console'><div class='limiter clearfix'>
      <?php print render($page['help']); ?>
      <?php if ($show_messages && $messages): print $messages; endif; ?>
    </div></div>
  <?php endif; ?>
  
  <?php if ($page['header']): ?>
    <div id='header' class='clearfix'>
      <?php print render($page['header']); ?>
    </div>
  <?php endif; ?>

  
  <?php if ($page['highlighted']): ?>
    <div id='highlighted'><div class='limiter clearfix'>
      <?php print render($page['highlighted']); ?>
    </div></div>
  <?php endif; ?>
  
  <div id='page' class='page clearfix'>
  
    <?php if ($page['sidebar_first']): ?>
      <div id='left' class='clearfix'><?php print render($page['sidebar_first']) ?></div>
    <?php endif; ?>
  
    <div class='main-content'>
      <?php if ($breadcrumb) print $breadcrumb; ?>
      <?php if ($title): ?><h1 class='page-title'><?php print $title ?></h1><?php endif; ?>
      <?php if ($primary_local_tasks): ?><ul class='links clearfix'><?php print render($primary_local_tasks) ?></ul><?php endif; ?>
      <?php if ($secondary_local_tasks): ?><ul class='links clearfix'><?php print render($secondary_local_tasks) ?></ul><?php endif; ?>
      <?php if ($action_links): ?><ul class='links clearfix'><?php print render($action_links); ?></ul><?php endif; ?>
      <div id='content' class='clearfix'><?php print render($page['content']) ?></div>
    </div>
  
    <?php if ($page['sidebar_second']): ?>
      <div id='right-rail' class='clearfix'><?php print render($page['sidebar_second']) ?></div>
    <?php endif; ?>
  
  </div>
  
  <div id="footer" class='clear'>
    <?php print render($page['footer']) ?>
    <div id="our-film-campaigns" class="footer-column-wrapper clearfix">
      <div class="column title">
        <a href="#">our film campaigns</a>
      </div><!--/column-->
      <?php print $film_camp_nav ?>
     </div>
     <div id="friends-of-takepart" class="footer-column-wrapper clearfix">
      <div class="column title">
        <a href="#">friends of takepart</a>
      </div><!--/column-->
      <?php print $friends_takepart_nav ?>
    </div>
    
    <div id="footer-set-links" class="footer-column-wrapper clearfix">
      <div class="column title">
        <a href="#" id="news-and-blogs">news &amp; blogs</a>
        <a href="#" id="issues">issues</a>
        <a href="#" id="actions">actions</a>
      </div><!--/column-->
      <?php print $takepart_topics_nav ?>
    </div>
    <div id="footer-links" class="clear clearfix">
      <ul class="clearfix" id="soc-links">
        <li id="fb">  <a target="_blank" href="http://www.facebook.com/takepart">facebook</a></li>
        <li id="twitter"> <a target="_blank" href="http://www.twitter.com/takepart">twitter</a></li>
      </ul>
      
      <ul class="clearfix" id="global-links">
        <li><a href="/about-us">About Us</a></li>
        <li><a href="/contact-us">Contact Us</a></li>
        <li><a href="/help">Help</a></li>
        <li><a href="/privacy-policy">Privacy Policy</a></li>
        <li class="last"><a href="/terms-of-use">Terms of Use</a></li>
      </ul>

    </div>     

    <div id="footer-about">
      <p>TakePart is the Social Action Network&trade; of <a target="_blank" href="http://www.participantmedia.com/">Participant Media</a></p>
      <div id="footer-legal">&copy; 2008-2011 TakePart, LLC</div>
    </div>

  </div>
</div>