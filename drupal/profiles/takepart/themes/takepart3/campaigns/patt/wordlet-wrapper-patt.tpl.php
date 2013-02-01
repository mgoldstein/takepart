<div id="page-wrapper" class="campaign">
	<?php print $header ?>

	<!-- start -->

	<div class="page-wrap">
		<div class="table int">
		
			<div class="header">
				<div class="logo">
					<a href="<?=wu('patt_home')?>"><img src="http://stage.bltdigital.com/apatt/images/interior-logo.png" width="357" height="206" alt="Interior Logo" usemap="#logo"></a>
				</div>
				<p class="mobile" id="mobile_back">
					<a href="<?=wu('patt_home')?>"><?=w('back')?></a>
				</p>
			</div>
			
			<div class="nav">
				<ul>
					<li><a href="<?=wu('patt_film')?>"><span>the film</span></a></li>
					<li><a href="<?=wu('patt_action')?>"><span>take action</span></a></li>
					<li><a href="<?=wu('patt_snap')?>"><span>gallery: snap alum</span></a></li>
					<li><a href="<?=wu('patt_book')?>"><span>the book</span></a></li>
					<li><a href="<?=wu('patt_alliances')?>"><span>alliances</span></a></li>
					<li><a href="/hunger"><span>news</span></a></li>
					<li><a href="<?=wu('patt_events')?>"><span>events + resources</span></a></li>
					<li><a href="<?=wu('patt_assistance')?>"><span>i need food assistance</span></a></li>
				</ul>
			</div>

			<div class="main">
				<?=$content?>
			</div>
			
		</div><!-- /.table -->
		
	</div><!-- /.page-wrap -->

	<!-- end -->

	<?php print $footer ?>
</div>