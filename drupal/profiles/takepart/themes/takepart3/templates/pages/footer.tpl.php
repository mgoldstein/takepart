
<div id="footer" class='clear'>

<?php print render($page['footer']) ?>
	<ul id="campaign-links">
		<li><a href="http://www.climatecrisis.net/" id="climate-crisis">Climate
				Crisis</a></li>
		<li><a href="http://www.savemyoceans.com/" id="save-my-oceans">Save My
				Oceans</a></li>
		<li><a href="http://www.foodincmovie.com/" id="hungry-for-change">Hungry
				For Change</a></li>
		<li><a href="http://www.waitingforsuperman.com/action/"
			id="waiting-for-superman">Waiting For Superman</a></li>
	</ul>
	
	<?php if(!(is_null($film_camp_nav) || empty($film_camp_nav))): ?>
	<div id="our-film-campaigns" class="footer-column-wrapper clearfix">
		<div class="column title">
			<a href="#">our film campaigns</a>
		</div>
		<!--/column-->
	  <?php print $film_camp_nav ?>
    </div>
    <?php endif; ?>
     
    <?php if(!(is_null($friends_takepart_nav) || empty($friends_takepart_nav))): ?> 
	<div id="friends-of-takepart" class="footer-column-wrapper clearfix">
		<div class="column title">
			<a href="#">friends of takepart</a>
		</div>
		<!--/column-->
      <?php print $friends_takepart_nav ?>
    </div>
    <?php endif; ?>
    

    <?php if(!(is_null($takepart_topics_nav) || empty($takepart_topics_nav))): ?>
	<div id="footer-set-links" class="footer-column-wrapper clearfix">
		<div class="column title">
			<a href="#">Topics</a>
		</div>
		<!--/column-->
      <?php print $takepart_topics_nav ?>
    </div>
    <?php endif; ?>
    
    <?php if(!(is_null($corporate_links_nav) || empty($corporate_links_nav))): ?>
	<div id="footer-links" class="clear clearfix">
		<ul class="clearfix" id="soc-links">
			<li id="fb"><a target="_blank"
				href="http://www.facebook.com/takepart">facebook</a></li>
			<li id="twitter"><a target="_blank"
				href="http://www.twitter.com/takepart">twitter</a></li>
		</ul>
		<!-- These should be converted to a menu, so TP can manage these links without changing code as they may change from time to time -->
      <?php print $corporate_links_nav;?>
    </div>
    <?php endif; ?>

	<div id="footer-about">
		<p>
			TakePart is the Social Action Network&trade; of <a target="_blank"
				href="http://www.participantmedia.com/">Participant Media</a>
		</p>
		<div id="footer-legal">
			&copy; 2008-
			<?php echo date('Y'); ?>
			TakePart, LLC
		</div>
	</div>

</div>
