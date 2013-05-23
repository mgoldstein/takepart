<div id="page-wrapper" class="campaign">
	<?=$header ?>

	<!-- start -->

	<div class="page-wrap">
		<div class="main">
			<header class="header">
				<? if ( $w = w('header_image') ): ?>
					<h1 <?=wa('header_image')?>>
						<span><?=$w->single?></span>
						<a href="<?=wu('intelchange_winners_home')?>"><img src="<?=$w->img_src?>" alt="intel for change logo" /></a>
					</h1>
				<? endif ?>
				<p class="presented" <?=wa('presented_by')?>>
					<? if ( $w = w('presented_by') ): ?>
						<span class="by"><?=$w->single(false)?></span>
						<img src="<?=$w->img_src?>" alt="intel logo" />
					<? endif ?>
				</p>
			</header>
			<nav class="menu">
				<ul <?=wa('menu')?>>
					<? foreach( wl('menu') as $w ): ?>
						<li>
							<a href="<?=$w->href?>" class="<?=ws($w->href)?>"><?=$w->single(false)?></a>
							<? if ($w->active): ?>
								<?
								if ( ws($w->href) == 'active' && isset($_GET['team'])) {
								    $cur_team = $_GET['team'];
								} elseif(ws($w->href) == 'active') {
								    $cur_team = w('teams')->token; //first team token
								}
								?>
								<ul>
									<? foreach( wl('teams') as $team ): ?>
									<li><a href="<?=$w->href?>?team=<?=$team->token?>" class='<?=($cur_team == $team->token ? "active" : "")?>'><?=$team->single(false)?></a></li>
									<? endforeach ?>
								</ul>
							<? endif ?>
						</li>
					<? endforeach ?>
				</ul>
				<script type="text/javascript">
					var addthis_share = {
					    url: "<?=wu('intelchange_winners_home')?>"
					}
				</script>
				<div class="addThis">
                    <a class="addthis_button_facebook_like" fb:like:layout="button_count" fb:like:action="recommend"></a>
                    <a class="addthis_button_tweet"></a>
                    <a class="addthis_button_email"></a>
                </div>
			</nav>
			<main id="page" class="content">
				<?=$content?>
			</main>
			<footer class="footer" <?=wa('footer_image')?>>
				<? if ( ($w = w('footer_image')) && $w->img_src ): ?>
					<img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" />
				<? endif ?>
			</footer>
		</div>
	</div><!-- /.page-wrap -->

	<!-- end -->

	<?=$footer ?>
</div>