<div class="column column-1">
	<div class="content">
		<ol>
			<? foreach ( wl('side_links') as $w ): ?>
				<li><a href="<?=$w->href?>">
					<?=$w->single?>
				</a></li>
			<? endforeach ?>
			<li><a href="#">purchase tickets</a></li>
			<li><a href="http://www.magpictures.com/dates.aspx?id=e016f484-4c9a-4401-8fbc-e19eb2119389">theaters</a></li>
			<li><a href="#">watch it on demand</a></li>
			<li><a href="http://www.magpictures.com/presskit.aspx?id=e016f484-4c9a-4401-8fbc-e19eb2119389">press kit</a></li>
			<li><a href="http://www.magpictures.com/presskit.aspx?id=e016f484-4c9a-4401-8fbc-e19eb2119389">photo gallery</a></li>
			<li><a href="http://www.magpictures.com/profile.aspx?id=e016f484-4c9a-4401-8fbc-e19eb2119389">reviews</a></li>
		</ol>
		<div class="social"><img src="http://stage.bltdigital.com/apatt/images/interior-social-icons.png" width="116" height="60" alt="Social Icons"></div>
	</div>
</div><!-- /.column-1 -->
<div class="column column-2">
	<div class="inner">
		<img src="http://stage.bltdigital.com/apatt/images/interior-main-header.png" width="434" height="25" alt="One Nation. Underfed.">
		<div class="overview">
			<?=w('body')?>
		</div>
	</div><!-- /.inner -->
</div><!-- /.column-2 -->
<div class="column column-3">
	<div class="content">
		<div class="email-signup">
			<form name="email-form" action="" method="get">
			<h3>email signup</h3>
		    <div class="input"><input type="text"  name="email"></div>
            <div class="submit"><input type="image" value="Submit" src="/profiles/takepart/themes/takepart3/campaigns/patt/images/interior-form-btn.png"></div>
			</form>
		</div>
		<div class="sponsored">
			<h4>sponsored by:</h4>
			<a href="#"><img src="http://stage.bltdigital.com/apatt/images/interior-participant-media-logo.png" width="151" height="49" alt="Participant Media Logo"></a>
		</div>
	</div>
</div><!-- /.column-3 -->