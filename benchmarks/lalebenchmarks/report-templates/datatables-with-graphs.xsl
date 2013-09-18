<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:output method="html" encoding="utf-8" indent="yes" />

	<xsl:template match="/content">
		<xsl:text disable-output-escaping='yes'>&lt;!DOCTYPE html></xsl:text>
		<html lang="en">
			<head>
				<meta name="viewport" content="width=device-width, initial-scale=1.0" />
				<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/2.0.3/jquery.min.js"></script>
				<script type="text/javascript" src="https://netdna.bootstrapcdn.com/bootstrap/3.0.0/js/bootstrap.min.js"></script>
				<link href="https://netdna.bootstrapcdn.com/bootstrap/3.0.0/css/bootstrap.min.css" rel="stylesheet" type="text/css" />
				<script type="text/javascript" src="https://www.google.com/jsapi"></script>
				<script type="text/javascript">
				<![CDATA[
					google.load('visualization', '1.0', {'packages':['corechart']});
					google.setOnLoadCallback(function() {
						var $ = jQuery;

						$("body section").each(function(i, section) {
							var data = domTableToData($(section).find("table"));
							data = google.visualization.arrayToDataTable(data);

							var userOptions = domOptionsToArray($(section).children("options"));
							var options = {
								title: $(section).find("h2").text(),
								pointSize: 5,
								hAxis: {
									title: userOptions.hAxis
								},
								vAxis: {
									title: userOptions.vAxis
								}
							};

							var chart = new google.visualization.LineChart($(section).find("graph").get(0));
							chart.draw(data, options);
						});

						$(".data-table-container .accordion-toggle").click(function() {
							$(this).parents(".data-table-container").find(".panel-collapse").toggle("slow");
						});

						function domTableToData($table) {
							var data = [];
							$table.find("tr").each(function(rowIndex) {
								var rowData = []
								$(this).find("td").each(function() {
									rowData.push(0 != rowIndex ? parseFloat($(this).text()) : $(this).text());
								});
								data.push(rowData);
							});
							return data;
						}

						function domOptionsToArray($options) {
							var options = {};
							$options.find("option").each(function(i, option) {
								options[$(option).attr("name")] = $(option).text();
							});
							return options;
						}
					});
				]]>
				</script>
				<style type="text/css">
				<![CDATA[
					section graph {
						height: 300px;
						width: 70%;
						display: block;
					}
					section table td {
						border: 1px solid gray;
						padding-right: 30px;
					}
				]]>
				</style>
			</head>
			<body>
				<div class="container">
					<xsl:for-each select="section">
						<section>
							<xsl:copy-of select="h2" />
							<graph />
							<xsl:copy-of select="options" />
							<xsl:apply-templates select="table" />
						</section>
					</xsl:for-each>
				</div>
			</body>
		</html>
	</xsl:template>

	<xsl:template match="/content/section/table">
		<div class="panel panel-default data-table-container">
			<div class="panel-heading">
				<h4 class="panel-title"><a class="accordion-toggle" href="#">Show data table</a></h4>
			</div>
			<div class="panel-collapse collapse">
				<div class="panel-body">
					<xsl:copy-of select="." />
				</div>
			</div>
		</div>
	</xsl:template>
</xsl:stylesheet>
