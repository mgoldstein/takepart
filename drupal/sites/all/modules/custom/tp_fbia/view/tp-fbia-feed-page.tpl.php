<rss version="2.0"
     xmlns:content="http://purl.org/rss/1.0/modules/content/">
  <channel>
    <title><?php print $title; ?></title>
    <link><?php print $url; ?></link>
    <description>
      <?php print $description; ?>
    </description>
    <language>en-us</language>
    <lastBuildDate><?php print $buildDate; ?></lastBuildDate>
      <?php foreach($items as $item): ?>
        <item>
          <?php print $item; ?>
        </item>
      <?php endforeach; ?>
</channel>
</rss>
