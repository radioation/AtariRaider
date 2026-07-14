
# 2-stick (4-pot) data



Some readings after moving [thumbsticks](https://www.amazon.com/dp/B0CPFDKWZF?ref=ppx_yo2ov_dt_b_fed_asin_title)
through entire range of motion.

```txt
ST1 X: [554] Min:36 Max:1023 ST1 Y: [482] Min:0 Max:994 ST2 X: [586] Min:39 Max:1023 ST2 Y: [446] Min:0 Max:987
ST1 X: [551] Min:36 Max:1023 ST1 Y: [480] Min:0 Max:994 ST2 X: [585] Min:39 Max:1023 ST2 Y: [447] Min:0 Max:987
ST1 X: [554] Min:36 Max:1023 ST1 Y: [481] Min:0 Max:994 ST2 X: [585] Min:39 Max:1023 ST2 Y: [445] Min:0 Max:987
ST1 X: [554] Min:36 Max:1023 ST1 Y: [479] Min:0 Max:994 ST2 X: [583] Min:39 Max:1023 ST2 Y: [445] Min:0 Max:987
ST1 X: [553] Min:36 Max:1023 ST1 Y: [481] Min:0 Max:994 ST2 X: [586] Min:39 Max:1023 ST2 Y: [446] Min:0 Max:987
ST1 X: [552] Min:36 Max:1023 ST1 Y: [481] Min:0 Max:994 ST2 X: [585] Min:39 Max:1023 ST2 Y: [446] Min:0 Max:987
ST1 X: [553] Min:36 Max:1023 ST1 Y: [481] Min:0 Max:994 ST2 X: [586] Min:39 Max:1023 ST2 Y: [445] Min:0 Max:987
ST1 X: [552] Min:36 Max:1023 ST1 Y: [482] Min:0 Max:994 ST2 X: [585] Min:39 Max:1023 ST2 Y: [447] Min:0 Max:987
ST1 X: [552] Min:36 Max:1023 ST1 Y: [481] Min:0 Max:994 ST2 X: [586] Min:39 Max:1023 ST2 Y: [447] Min:0 Max:987
```

* At rest values are in []
Seeing midpoints for sticks ranging 447 to 586

* Min/Max ranges:

  * 1X 36-1023 ( 987 )
  * 1Y 0-994   ( 994 ) actual ( 29 -1023)
  * 2X 39-1023 ( 984 )
  * 2Y 0-987   ( 987 ) actual ( 36 -1023)
__Note__*Y's are inverted to match 5200 code.*

without moving stick
```txt
ST1 X: [554] Min:552 Max:556 ST1 Y: [478] Min:476 Max:481 ST2 X: [598] Min:595 Max:600 ST2 Y: [434] Min:430 Max:436
ST1 X: [554] Min:552 Max:556 ST1 Y: [478] Min:476 Max:481 ST2 X: [597] Min:595 Max:600 ST2 Y: [432] Min:430 Max:436
ST1 X: [554] Min:552 Max:556 ST1 Y: [478] Min:476 Max:481 ST2 X: [597] Min:595 Max:600 ST2 Y: [433] Min:430 Max:436
ST1 X: [554] Min:552 Max:556 ST1 Y: [479] Min:476 Max:481 ST2 X: [597] Min:595 Max:600 ST2 Y: [433] Min:430 Max:436
ST1 X: [553] Min:552 Max:556 ST1 Y: [479] Min:476 Max:481 ST2 X: [597] Min:595 Max:600 ST2 Y: [433] Min:430 Max:436
```

# 1-stick data 

```txt
ST1 X: [552] Min:552 Max:556 ST1 Y: [478] Min:476 Max:480
ST1 X: [553] Min:552 Max:556 ST1 Y: [479] Min:476 Max:480
ST1 X: [553] Min:552 Max:556 ST1 Y: [477] Min:476 Max:480
```


# Hline counter / Interrupts
* Hline counter seems to get stuck at 258 (just outside of max) if arduino is powered
  up first or if Atari is cold rebooted during a run.

