<div class="slim-nav-inner clearfix">
	<div class="menu-toggle"></div>
	<div class="left">
	  <div class="logo">
	    <?php print $logo; ?>
	  </div>
	  <nav id="main-menu">
	    <?php print $slimnav; ?>
	  </nav>
	</div>
	<div class="right">
	  <div class="follow-us horizontal-menu menu-horizontal">
		<h2 class="follow-headline">Follow</h2>
	    <?php print $social_menu; ?>
	  </div>
	  <div class="user-menu">
	    <div class="tpsLogin" data-layout="compact"></div>
	  </div>
	  <?php print render($search); ?>
	</div>
</div>
