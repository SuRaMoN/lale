<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:template match="/TestCase">
		<content>
			<xsl:apply-templates select="TestFunction" />
		</content>
	</xsl:template>

	<xsl:template match="/TestCase[@name='lalebenchmarks::core::RouletteWheelBenchmark']/TestFunction[@name='testRouletteSpeed']">
		<section>
			<h2>Roullette speed naive vs optimized</h2>
			<options>
				<option name="vAxis">Select speed (ms)</option>
				<option name="hAxis">Size (no of areas)</option>
			</options>
			<table>
				<tr>
					<td>Size</td>
					<td>Naive</td>
					<td>Optimized</td>
				</tr>
				<xsl:for-each select="BenchmarkResult">
					<xsl:sort data-type="number" select="substring-before(substring-after(@tag, 'size: '), ',')" />
					<xsl:if test="starts-with(@tag, 'naive')">
						<xsl:variable name="size" select="substring-before(substring-after(@tag, 'size: '), ',')" />
						<xsl:variable name="optimizedValue" select="../BenchmarkResult[contains(@tag, concat('size: ', $size)) and contains(@tag, 'optimized')]/@value" />
						<xsl:variable name="optimizedIterations" select="../BenchmarkResult[contains(@tag, concat('size: ', $size)) and contains(@tag, 'optimized')]/@iterations" />
						<tr>
							<td><xsl:value-of select="$size" /></td>
							<td><xsl:value-of select="number(@value) div number(@iterations)" /></td>
							<td><xsl:value-of select="number($optimizedValue) div number($optimizedIterations)" /></td>
						</tr>
					</xsl:if>
				</xsl:for-each>
			</table>
		</section>
	</xsl:template>
</xsl:stylesheet>
