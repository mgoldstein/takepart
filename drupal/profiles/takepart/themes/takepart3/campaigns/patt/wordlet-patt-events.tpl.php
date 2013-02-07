<div class="two-columns">
	<div class="column column-2">
		<div class="inner">
			<div class="overview">
				<?=w('body')?>
			</div>
		</div><!-- /.inner -->
	</div><!-- /.column-2 -->
	<? var_dump(__FILE__) ?>
	<? var_dump(__DIR__) ?>
	<? var_dump(file_exists(__DIR__ . '/subtemplates/-patt-right.tpl.php')) ?>
	<? include_once('subtemplates/-patt-right.tpl.php') ?>
<?
if ($handle = opendir(__DIR__ . '/subtemplates')) {
    echo "Directory handle: $handle\n";
    echo "Entries:\n";

    /* This is the correct way to loop over the directory. */
    while (false !== ($entry = readdir($handle))) {
        echo "$entry\n";
    }

    /* This is the WRONG way to loop over the directory. */
    while ($entry = readdir($handle)) {
        echo "$entry\n";
    }

    closedir($handle);
} ?>
</div>