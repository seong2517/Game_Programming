# HTML CHART

### 사용한 CHART 사이트
>[Chart.js](https://www.w3schools.com/js/js_graphics_chartjs.asp)   
>[ECharts](https://echarts.apache.org/en/index.html)   
>[D3.js](https://d3js.org/)
 * **[Chart.js](https://www.w3schools.com/js/tryit.asp?filename=tryai_chartjs_pie) : 원형그래프 차트로 제작(2021년 대한민국 연령대별 인구 비중)**   
        new Chart("myChart", {
        type: "pie",
        data: {
          labels: xValues,
          datasets: [
            {
              backgroundColor: barColors,
              data: yValues,
            },
          ],
        },
 * **[ECharts](https://echarts.apache.org/examples/en/editor.html?c=line-simple) : 기본선 차트로 제작(2011~2020년 대한민국의 연 강수량)**
           xAxis: {type: "category",data: ["2011","2012","2013","2014","2015","2016","2017","2018","2019","2020"]},
           yAxis: {type: "value"},
           series: [{data: [1623, 1479, 1163, 1174, 949, 1273, 968, 1387, 1172, 1591],type: "line"}],   
 * **[D3.js](https://d3js.org/) : 세로막대형 차트로 제작(2021년 대한민국 연령대별 인구 비중)**   
      d3.select(".chart")
        .selectAll("div")
        .data(data)
        .enter()
        .append("div")
        .style("width", function (d) {
          return d * 50 + "px";
        })
        .text(function (d) {
          return d + "%";
        });
### 호스팅 주소
> [netlify](https://amazing-dusk-45e341.netlify.app/)
