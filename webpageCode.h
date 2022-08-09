const char webpageCode[] =
    R"=====( 
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Home Automation Controller</title>
    <style>
        .heading {
            font-family: 'Courier New', Courier, monospace;
            text-align: center;
            color: blueviolet;
            background-color: aquamarine;
        }

        .switch {
            width: 100%;
            height: 500px;
            background-color: bisque;
        }

        .component {
            margin: 10px;
            width: 150px;
            height: 50px;
            background-color: aliceblue;
            border: solid black 1px;
            border-radius: 10px;
            box-shadow: 5px 5px 3px orangered;
            font-family: 'Gill Sans', 'Gill Sans MT', Calibri, 'Trebuchet MS', sans-serif;
            font-size: medium;
        }

        .active {
            margin: 10px;
            width: 150px;
            height: 50px;
            background-color: orangered;
            border: solid black 1px;
            border-radius: 10px;
            font-family: 'Gill Sans', 'Gill Sans MT', Calibri, 'Trebuchet MS', sans-serif;
            font-size: medium;
        }

        .component:hover {
            box-shadow: 7px 7px 5px orangered;
        }
    </style>
</head>

<body>
    <h1 class="heading">Home Controller System</h1>
    <div class="switch">
        <button id="li1" class="component">LIGHT 1 <b>ON/OFF</b></button>
        <button id="li2" class="component">LIGHT 2 <b>ON/OFF</b></button>
        <button id="fan1" class="component">FAN 1 <b>ON/OFF</b></button>
        <button id="fan2" class="component">FAN 2 <b>ON/OFF</b></button>
    </div>
</body>
<script>
    var light1 = document.getElementById("li1")
    var light2 = document.getElementById("li2")
    var fan1 = document.getElementById("fan1")
    var fan2 = document.getElementById("fan2")
    //light 1
    light1.addEventListener('click', function () {
        if (this.className == "component") {
            if (confirm("Press OK button to ON!")) {
                this.className = "active";
                //get request for ON
                fetch('http://192.168.4.1/update?Light_1=on');
                this.innerHTML = "LIGHT 1 ON/<b>OFF</b>";
            }
        } else {
            this.className = "component";
            //get request for OFF
            fetch('http://192.168.4.1/update?Light_1=off');
            this.innerHTML = "LIGHT 1 <b>ON/</b>OFF";
        }
    })
    //light 2
    light2.addEventListener('click', function () {
        if (this.className == "component") {
            if (confirm("Press OK button to ON!")) {
                this.className = "active";
                //get request for ON
                fetch('http://192.168.4.1/update?Light_2=on');
                this.innerHTML = "LIGHT 2 ON/<b>OFF</b>";
            }
        } else {
            this.className = "component";
            //get request for OFF
            fetch('http://192.168.4.1/update?Light_2=off');
            this.innerHTML = "LIGHT 2 <b>ON/</b>OFF";
        }
    })
    //fan 1
    fan1.addEventListener('click', function () {
        if (this.className == "component") {
            if (confirm("Press OK button to ON!")) {
                this.className = "active";
                //get request for ON
                fetch('http://192.168.4.1/update?Fan_1=on');
                this.innerHTML = "FAN 1 ON/<b>OFF</b>";
            }
        } else {
            this.className = "component";
            //get request for OFF
            fetch('http://192.168.4.1/update?Fan_1=off');
            this.innerHTML = "FAN 1 <b>ON/</b>OFF";
        }
    })
    //fan 2
    fan2.addEventListener('click', function () {
        if (this.className == "component") {
            if (confirm("Press OK button to ON!")) {
                this.className = "active";
                //get request for ON
                fetch('http://192.168.4.1/update?Fan_2=on');
                this.innerHTML = "FAN 2 ON/<b>OFF</b>";
            }
        } else {
            this.className = "component";
            //get request for OFF
            fetch('http://192.168.4.1/update?Fan_2=off');
            this.innerHTML = "FAN 2 <b>ON/</b>OFF";
        }
    })

</script>

</html>
)=====";