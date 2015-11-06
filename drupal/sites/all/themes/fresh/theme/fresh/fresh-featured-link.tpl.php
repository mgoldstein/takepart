<div class = "feature-article-small">
 <?php
    if (isset($variables[0])) {
      if (empty($variables[0]['url']) && !empty($variables[0]['title'])) {
        print '<p class = "featured-link">' . $variables[0]['title'] . '</p>';
      }
      else if (isset($variables[0]['url']) && isset($variables[0]['title'])) {
        print '<a href = ' . $variables[0]['url'] . ' class = "featured-link">' . $variables[0]['title'] . '</a>';
      }
    }
 ?>
</div>
