<? /*
<h1>Article Node Template Variables</h1>
<dl>
  <?php foreach(array_keys($variables) as $name): ?>
    <dt><?php print $name; ?></dt>
    <dd><pre><?php
      $repr = print_r($variables[$name], TRUE);
      print htmlentities($repr);
    ?></pre></dd>
  <?php endforeach; ?>
</dl>
* /
?>
<pre>
<?=drupal_realpath('public://profiles/photos/AbbySchanfield.jpg');?>

<?=theme('image', $variables)?>
<? 
	var_dump(array_keys($variables));
	var_dump($node);
?>
</pre>

<?=render(field_view_field('node', $node, 'body')); ?>
 

<?*/

?>

<article id="article-main">
	<header id="article-header">
		<h1 id="article-headline"><?=_s($title) ?></h1>
		<p id="article-abstract"><?=_s($field_article_subhead) ?></p>
		<div class="secondary">
			<p id="article-badge">{Article Badge}</p>
			<p id="article-date"><?=$date?><? //=date('F j, Y', )?></p>
			<ul id="article-author-names">
				<? while ( $author = _seach($field_author) ): ?>
					<li>
						<a href="{Author link}"><?=_s($author->title) ?></a>
					</li>
				<? endwhile ?>
			</ul>
		</div>
	</header>

	<div id="article-sidebar">
		<aside id="article-social" class="social"><div class="inner">
			<div id="article-tab">
				{Take Action Button}
			</div>
			<div class="tp-social" id="article-share"></div>
			<p id="article-comments-link" class="comments-link">
				<a href="#article-comments"><?=t('Comments') ?><span class="count"></span></a>
			</p>
		</div></aside>

		<aside id="article-author"><div class="inner">
			<? if ( $author = _snode($field_author) ): ?>
				<p class="image">
					<?=_simage($author->field_profile_photo)?>
				</p>
				<h3 class="headline"><?=_s($author->title) ?></h3>
				<? if ( $abody = $author->body->value() ): ?>
					<div class="body">
						<?=$abody['summary'] ?>
						<a href="#">{Full Bio}</a>
					</div>
				<? endif ?>
				{Follow me}
			<? endif ?>
		</div></aside>
	</div>

	<div id="article-content">
		<div id="article-image">
			<?=_simage($field_article_main_image)?>
		</div>

		<div id="article-body" class="cms">
			<?=_s($body)?>
		</div>

		<footer id="article-footer">
			<nav id="next-article">
				<h3 class="headline"><?=t('Next Article') ?></h3>
				<p><a href="#">{Next Article Next Article Next Article Next Article Next Article Next Article}</a></p>
			</nav>
			<nav id="article-tags">
				<h3 class="headline">
					<?=t('Get More:') ?>
				</h3>
				<ul>
					<? while ( $tag = _seach($field_topic) ): ?>
						<li>
							<a href="#"><?=$tag->name ?></a>
						</li>
					<? endwhile ?>

					<? while ( $tag = _seach($field_free_tag) ): ?>
						<li>
							<a href="#"><?=$tag->name ?></a>
						</li>
					<? endwhile ?>
				</ul>
			</nav>
		</footer>

		<section id="article-comments" class="comments">
			<h3><?=t('Comments') ?> <span class="count"></span></h3>
			{Comments module}
		</section>

		<section class="follow_us">
			<h3><?=t('Follow Us') ?></h3>
			<ul>
				<li class="facebook"><a href="#"><?=t('Facebook') ?></a></li>
				<li class="twitter"><a href="#"><?=t('Twitter') ?></a></li>
				<li class="google"><a href="#"><?=t('Google+') ?></a></li>
				<li class="pinterest"><a href="#"><?=t('Pinterest') ?></a></li>
				<li class="youtube"><a href="#"><?=t('YouTube') ?></a></li>
				<li class="tumblr"><a href="#"><?=t('Tumblr') ?></a></li>
			</ul>
		</section>

<pre>
-----------------
<? var_dump(array_keys(get_defined_vars())) ?>

-----------------
-----------------
</pre>
	</div>
</article>