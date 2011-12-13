<?xml version="1.0" encoding="iso-8859-1"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
  <head>
    <title><xsl:value-of select="rss/channel/title"/>RSS Feed</title>
    <style type="text/css">
    @import url(/profiles/takepart/modules/views_takepart_feeds/rss.css);
    </style>
  </head>
  <body>
    <div id="title">
      <h1><xsl:value-of select="rss/channel/title"/></h1>
    </div>
    <div id="content">
      <xsl:for-each select="rss/channel/item">
      <div class="article">
        <h2><a href="{link}" rel="bookmark"><xsl:value-of select="title"/></a></h2>
        <xsl:value-of select="description"/>
        <xsl:value-of select="content"/>
      </div>
      </xsl:for-each>
    </div>
  </body>
</html>
</xsl:template>
</xsl:stylesheet>