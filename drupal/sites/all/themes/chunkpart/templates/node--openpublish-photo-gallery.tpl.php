<article id="gallery-main" class="<?=!$node->status ? 'unpublished':'' ?>">
	<div id="gallery-main-inner">
		<header id="gallery-header">
			<h1 id="gallery-headline"><?=_s($node->title) ?></h1>
			<p id="gallery-abstract"><?=_s($node, 'field_subhead') ?></p>
			<div class="secondary">
				<p id="gallery-date"><?=date('F j, Y', $node->created)?></p>

				<ul id="gallery-author-names">
					<? if ( $authors = _snode($node, 'field_author') ): ?>
						<? while ( list($key, $author) = _seach($authors) ): ?>
							<li class="<?=($key == 0)?'first-child':''?> <?=($key == count($field_author) - 1)?'last-child':''?>">
								<a href="<?=_surl($author)?>" rel="author"><?=$author->title ?></a>
							</li>
						<? endwhile ?>
					<? endif ?>
				</ul>
			</div>
		</header>

		<div id="gallery-sidebar">
			<aside id="gallery-social" class="social"><div class="inner">
				<div id="gallery-tab">
					<p class="takepart-take-action"></p>
				</div><!--
				--><div class="tp-social" id="gallery-share"></div>
				<p id="gallery-comments-link" class="comments-link">
					<a href="#gallery-comments"><?=t('Comments') ?><span class="count"></span></a>
				</p>
				<div id="gallery-social-more">
					<h4 class="trigger"><a href="#gallery-more-shares">More</a></h4>
					<div id="gallery-more-shares">
						<h5 class="header"><?=t('Share with your friends') ?></h5>
						<p></p>
					</div>
				</div>
			</div></aside>
		</div>

		<div id="gallery-content">
Cover Page:
			<?=_simage($node, 'field_thumbnail') ?>

			<? if ( $content['body'] ): ?>
				<div id="gallery-body" class="cms">
					<?=render($content['body'])?>
				</div>
			<? endif ?>
Gallery:
			<ul>
				<? if ( $images = _snode($node, 'field_gallery_images') ): ?>
					<? while ( list($key, $image) = _seach($images) ): ?>
						<li>
							<figure>
								<?=_simage($image) ?>
								<figcaption>
									<?=_s($image['file'], 'field_image_title', 'file') ?>
									<?=_s($image['file'], 'field_media_caption', 'file') ?>
								</figcaption>
							<figure>
						</li>
					<? endwhile ?>
				<? endif ?>
			</ul>

			<footer id="gallery-footer">
				<? if ( $relateds = field_get_items('node', $node, 'field_related_stories') ): ?>
					<nav id="gallery-related">
						<h3><?=t('Related stories on TakePart:') ?></h3>
						<ul>
							<? while ( list($key, $related) = _seach($relateds) ): ?>
								<li><a href="<?=_surl($related) ?>"><?=$related->title ?></a></li>
							<? endwhile ?>
						</ul>
					</nav>
				<? endif ?>

				<? if ( $next_gallery ): ?>
					<nav id="next-article">
						<a href="<?=$next_gallery->href ?>">
							<?=_simage($next_gallery->node, 'field_thumbnail') ?>
							<p><?=_s($next_gallery->title) ?></p>
							<h3 class="headline"><?=t('Enter Photo Gallery') ?></h3>
						</a>
					</nav>
				<? endif ?>

				<nav id="gallery-tags">
					<h3 class="headline">
						<?=t('Get More:') ?>
					</h3>

					<ul>
						<? if ( $field_topic = _snode($node, 'field_topic') ): ?>
							<? while ( list($key, $tag) = _seach($field_topic) ): ?>
								<li><a href="<?=_surl($tag) ?>"><?=$tag->name ?></a></li>
							<? endwhile ?>
						<? endif ?>

						<? if ( $field_free_tag = _snode($node, 'field_free_tag') ): ?>
							<? while ( list($key, $tag) = _seach($field_free_tag) ): ?>
								<li><a href="<?=_surl($tag) ?>"><?=$tag->name ?></a></li>
							<? endwhile ?>
						<? endif ?>
					</ul>
				</nav>
			</footer>

			<div id="gallery-comments">
				<?=drupal_render(module_invoke('comment_block_simple', 'block_view', 'comment_block')) ?>
			</div>
		</div>
	</div>
Topic:
	<? if ( $field_topic_box = _snode($node, 'field_topic_box') ): ?>
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
