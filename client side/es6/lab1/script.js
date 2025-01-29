/*var opts = ["o1", "o2", "o2"];
for (var j = 0; j < opts.length; j ++)
{
    
    var option = document.createElement("option");
    option.text = opts[j];
    document.getElementById("s1").add(option);
} */
var xhr = new XMLHttpRequest();
xhr.open("GET", "rockbands.json");
xhr.onreadystatechange = function()
{
    if (xhr.readyState == 4 && xhr.status >= 200 && xhr.status < 300)
    {
        //console.log(xhr.responseText);
        var data = JSON.parse(xhr.responseText);
        //console.log(data);
        var s1 = document.getElementById('s1');
        for (i in data)
        {
            var option = document.createElement("option");
            option.text = i;
            s1.add(option);
        }
        s1.onchange = function(){
            var s2 = document.getElementById('s2');
            while(s2.options.length > 0)
            {
                s2.remove(0);
            }
            for (i of data[s1.value])
            {
                option = document.createElement("option");
                option.text = i.name;
                option.value = i.value;
                s2.add(option);
            }
            s2.onchange = function()
            {
                var win = open(s2.value);
            }
        }
    }
}
xhr.send();
