<article id="article-main" class="article <?=!$node->status ? 'unpublished':'' ?>"
	<? if ( $series = _snode($node, 'field_series') ): ?>
		<? while ( list($key, $serie) = _seach($series) ): ?>
			data-series="<?=htmlspecialchars($serie->name) ?>"
		<? endwhile ?>
	<? endif ?>
	>
	<div id="article-main-inner">
		<header class="article-header">
			<h1 class="article-headline"><?=_s($title) ?></h1>
			<p class="article-abstract"><?=_s($field_article_subhead) ?></p>
			<div class="header-secondary">
				<? if ( list($key, $badge) = _seach($field_significance) ): ?>
					<p class="badge"><a href="<?=_surl($badge)?>"><?=$badge->name?></a></p>
				<? endif ?>
				<time class="pubdate"><?=date('F j, Y', $node->created)?></time>
				<address class="authors">
					<? while ( list($key, $author) = _seach($field_author) ): ?>
						<span class="author <?=($key == 0)?'first-child':''?> <?=($key == count($field_author) - 1)?'last-child':''?>">
							<a href="<?=_surl($author)?>" rel="author"><?=$author->title ?></a>
						</span>
					<? endwhile ?>
				</address>
			</div>
		</header>

		<div id="article-sidebar">
			<aside id="article-social" class="social"><div class="inner">
				<div id="article-tab">
					<p class="takepart-take-action"></p>
				</div><!--
				--><div class="tp-social" id="article-share"></div>
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
						<?=_simage($author, 'field_profile_photo', 'node', 'tp_article_author_bio_photo') ?>
					</p>
					<h3 class="headline"><?=$author->title ?></h3>

					<? if ( $abody = _snode($author, 'body') ): ?>
						<div class="body">
							<?=$abody[0]['summary'] ?>
							<p class="full_bio_link">
								<a href="<?=_surl($field_author)?>"><?=t('Full Bio') ?></a>
							</p>
						</div>
					<? endif ?>

					<? if ( ($aftwitter = _snode($author, 'field_follow_twitter')) && ($afgoogle = _snode($author, 'field_follow_google')) ): ?>
						<h4 class="follow_headline"><?=t('Follow Me') ?></h4>
						<ul class="follow">
							<? if ( $aftwitter[0]['url'] ): ?>
								<li class="twitter"><a href="<?=$aftwitter[0]['url'] ?>"><?=$aftwitter[0]['title'] ?></a></li>
							<? endif ?>

							<? if ( $afgoogle[0]['url'] ): ?>
								<li class="google"><a href="<?=$afgoogle[0]['url'] ?>"><?=$afgoogle[0]['title'] ?></a></li>
							<? endif ?>
						</ul>
					<? endif ?>
				<? endif ?>
			</div></aside>
		</div>

		<div id="article-content">
			<figure id="article-image" class="<?=_ssettings($node, 'field_main_image_format', 'node', 'image_style') ?>">
				<?=_simage($node, 'field_article_main_image', 'node', _snode($node, 'field_main_image_format')) ?>

				<? if ( ($image = _snode($node, 'field_article_main_image')) ): ?>
					<? if ( $caption = _s($image[0]['file'], 'field_media_caption', 'file') ): ?>
						<figcaption>
							<?=_s($caption) ?>
						</figcaption>
					<? endif ?>
				<? endif ?>
			</figure>

			<? if ( $content['body'] ): ?>
				<div id="article-body" class="cms">
					<div class="content">
						<?=render($content['body'])?>
					</div>
				</div>
			<? endif ?>

			<footer id="article-footer">
				<? if ( $next_article ): ?>
					<nav id="next-article" class="related next-article">
						<h3 class="headline"><?=t('Next Article') ?></h3>
						<p>
							<a href="<?=$next_article->href ?>">
								<?=$next_article->title ?>
							</a>
						</p>
					</nav>
				<? endif ?>

				<? if ( $relateds = field_get_items('node', $node, 'field_related_stories') ): ?>
					<nav id="article-related" class="related related-stories">
						<h3 class="headline"><?=t('Related stories on TakePart') ?></h3>
						<ul>
							<? while ( list($key, $related) = _seach($relateds) ): ?>
								<li><a href="<?=_surl($related) ?>"><?=$related->title ?></a></li>
							<? endwhile ?>
						</ul>
					</nav>
				<? endif ?>

				<nav id="article-tags" class="page-tags">
					<h3 class="headline">
						<?=t('Get More') ?>
					</h3>

					<ul>
						<? while ( list($key, $tag) = _seach($field_topic) ): ?>
							<li><a href="<?=_surl($tag) ?>"><?=$tag->name ?></a></li>
						<? endwhile ?>

						<? while ( list($key, $tag) = _seach($field_free_tag) ): ?>
							<li><a href="<?=_surl($tag) ?>"><?=$tag->name ?></a></li>
						<? endwhile ?>
					</ul>
				</nav>

				<div class="OUTBRAIN" data-src="<?=_surl($node) ?>" data-widget-id="AR_3" data-ob-template="TakePart" ></div>
				<script type="text/javascript" async="async" src="http://widgets.outbrain.com/outbrain.js"></script>

				<? if ( isset($node_region['bean_on-our-radar-block']) ): ?>
					<?=render($node_region['bean_on-our-radar-block']) ?>
				<? endif ?>

				<div id="article-comments">
					<?=drupal_render(module_invoke('comment_block_simple', 'block_view', 'comment_block')) ?>
				</div>
			</footer>
		</div>
	</div>
	<? if ( $field_topic_box ): ?>
		<aside id="topic_box">
			<ul>
				<? while ( list($key, $topic) = _seach($field_topic_box) ): ?>
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
