<?php /* Content items returned for FBIA feed */?>
<title><?php print $title; ?></title>
<link><?php print $link; ?></link>
<guid><?php print $guid; ?></guid>
<pubDate><?php print $pubDate; ?></pubDate>
<?php foreach($authors as $author): ?>
  <author><?php print $author; ?></author>
<?php endforeach; ?>
<description><?php print $description; ?></description>
<content:encoded>
  <![CDATA[
    <?php print $content; ?>
  ]]>
</content:encoded>
