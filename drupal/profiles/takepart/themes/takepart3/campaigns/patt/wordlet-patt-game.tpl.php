<div class="column column-1">
  <div class="content">
    <h4 class="side_header">
      <?=w('side_header')?>
    </h4>
    <ol <?=wa('side_links')?>>
      <? foreach ( wl('side_links') as $w ): ?>
        <li><a href="<?=$w->href?>">
          <span><span><?=$w->single(false)?></span></span>
        </a></li>
      <? endforeach ?>
    </ol>
  </div>
</div><!-- /.column-1 -->
<div class="column column-2">
  <div class="inner">
    <div class="overview">
      <div class="cms">
        <?=w('body')?>
      </div>
      <div class="sms">
        <?=w('sms')?>
      </div>
    </div>
  </div><!-- /.inner -->
</div><!-- /.column-2 -->
<? include_once('subtemplates/patt-right.tpl.php') ?>