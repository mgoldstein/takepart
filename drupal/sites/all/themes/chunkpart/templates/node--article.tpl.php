<article id="article-main">
	<div id="article-main-inner">
		<header id="article-header">
			<h1 id="article-headline"><?=_s($title) ?></h1>
			<p id="article-abstract"><?=_s($field_article_subhead) ?></p>
			<div class="secondary">
				<? if ( $badge = _seach($field_significance) ): ?>
					<p id="article-badge"><a href="<?=_surl($badge)?>"><?=$badge->name?></a></p>
				<? endif ?>
				<p id="article-date"><?=date('F j, Y', $node->created)?></p>
				<ul id="article-author-names">
					<? while ( $author = _seach($field_author) ): ?>
						<li>
							<a href="<?=_surl($author)?>"><?=$author->title ?></a>
						</li>
					<? endwhile ?>
				</ul>
			</div>
		</header>

		<div id="article-sidebar">
			<aside id="article-social" class="social"><div class="inner">
				<div id="article-tab">
					<p class="takepart-take-action"></p>
				</div>
				<div class="tp-social" id="article-share"></div>
				<p id="article-comments-link" class="comments-link">
					<a href="#article-comments"><?=t('Comments') ?><span class="count"></span></a>
				</p>
				<div id="article-social-more">
					<h4 class="trigger"><a href="#article-more-shares">More</a></h4>
					<div id="article-more-shares">
						<h5 class="header"><?=t('Share with your friends') ?></h5>
						<p></p>
					</div>
				</div>
			</div></aside>

			<aside id="article-author"><div class="inner">
				<? if ( $author = _snode($field_author) ): ?>
					<p class="image">
						<?=_simage($author, 'field_profile_photo')?>
					</p>
					<h3 class="headline"><?=$author->title ?></h3>

					<? if ( $abody = _s($author, 'body') ): ?>
						<div class="body">
							<?=$abody['summary'] ?>
							<a href="<?=_surl($field_author)?>"><?=t('Full Bio') ?></a>
						</div>
					<? endif ?>

					<? if ( ($aftwitter = _s($author, 'field_follow_twitter')) && ($afgoogle = _s($author, 'field_follow_google')) ): ?>
						<ul class="follow">
							<? if ( $aftwitter['url'] ): ?>
								<li class="twitter"><a href="<?=$aftwitter['url'] ?>"><?=$aftwitter['title'] ?></a></li>
							<? endif ?>

							<? if ( $afgoogle['url'] ): ?>
								<li class="google"><a href="<?=$afgoogle['url'] ?>"><?=$afgoogle['title'] ?></a></li>
							<? endif ?>
						</ul>
					<? endif ?>
				<? endif ?>
			</div></aside>
		</div>

		<div id="article-content">
			<div id="article-image">
				<?=_simage($node, 'field_article_main_image')?>
			</div>

			<? if ( $body = _s($node, 'body') ): ?>
				<div id="article-body" class="cms">
					<?=$body['safe_value']?>
				</div>
			<? endif ?>

			<footer id="article-footer">
				<? if ( $next_article): ?>
					<nav id="next-article">
						<a href="<?=$next_article->href ?>">
							<h3 class="headline"><?=t('Next Article') ?></h3><!--
							--><p><?=$next_article->title ?></p>
						</a>
					</nav>
				<? endif ?>

				<nav id="article-tags">
					<h3 class="headline">
						<?=t('Get More:') ?>
					</h3>

					<ul>
						<? while ( $tag = _seach($field_topic) ): ?>
							<li><a href="<?=_surl($tag) ?>"><?=$tag->name ?></a></li>
						<? endwhile ?>

						<? while ( $tag = _seach($field_free_tag) ): ?>
							<li><a href="<?=_surl($tag) ?>"><?=$tag->name ?></a></li>
						<? endwhile ?>
					</ul>
				</nav>
			</footer>

			<?=drupal_render(module_invoke('comment_block_simple', 'block_view', 'comment_block')) ?>
		</div>
	</div>
	<? if ( $field_topic_box ): ?>
		<aside id="topic_box">
			<ul>
				<? while ( $topic = _seach($field_topic_box) ): ?>
					<li>
						<? if ( $link = _slink($topic, 'field_topic_box_link') ): ?>
							<a href="<?=($link['url'])?$link['url']:'#' ?>">
								<?=_simage($topic, 'field_topic_box_image') ?>
							</a>
						<? else: ?>
							<?=_simage($topic, 'field_topic_box_image') ?>						
						<? endif ?>
					</li>
				<? endwhile ?>
			</ul>
		</aside>
	<? endif ?>
</article>