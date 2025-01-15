# Home Assistant/ESPHome Display
The code driving my Waveshare E-Paper 7.5" display, as well as the Home Assistant sensors providing the data.

<div align="center">

<span style="color: white; background-color: #FF0000; display: inline-block; padding: 10px 20px; border-radius: 5px; font-weight: bold; font-size: 1.2em;">

```diff
⚠️

The esphome code is buggy. 
When I started setting it up I haven't written a line of c++ for about 8 years. 

Whenever I remembered something that made the code better I only applied it from then onwards; 
I didn't rework the already written code. 

Use at your own risk.
```

</span>

</div>


## Display Elements
It has the following elements on screen:

- Location for me and my SO
- Whether our plants need to be watered
- Current weather & 6 hour forecast
- Calendar entries for today & tomorrow
- The arrival times of our most frequently used U-Bahn, S-Bahn and bus lines at our stops

## Home Assistant Sensors

The data is mostly provided by multiscrape sensors. The reason for this is simple: the regular weather integrations weren't providing the exact attributes I wanted, and there's no proper integration for Berlin's public transport system.

### Person Tracker

Device trackers coming from our iPhones through the HA app's default integration.

### Plants

A simple sensor that sets Wet/Dry based on a "last watered" timestamp, updated by scanning an NFC tag each time we water our plants.  
WIP: I'm also building esp32 driven moisture sensors, to be integrated later.

### Weather

Provided by a multiscrape entity, data scraped from OpenMeteo's API.  
Since pulling for 1 day provides data for 00:00-23:59 for the current day, two days are scraped, and the data for the next 6 hours are read.

The setup is horribly inefficient due to Copilot autocompleting the names with written out words instead of numbers, making for loops impossible/ineffective.  
@Todo is to change this both for the sensors and in the esphome display's code.

### Calendar

It was surprisingly annoying to set up. Google Calendar integration, with two automations fetching the events for today and tomorrow and storing them in text variables.  
This is then fetched by esphome to display the events.  
@Todo for this is to send the data already stripped and formatted to esphome to reduce the processing needed by the driver

### Transport

Multiscrape fetching data from BVG's API. It stores both timestamps and minutes-until, but for this integration only the minutes are used.

## Attribution

* Plants picture provided by [Freepik](https://www.flaticon.com/free-icons/plant)
* BVG Data scraped through @derhuerst's [bvg-rest](https://github.com/derhuerst/bvg-rest)  
* Weather data scraped from [Open-Meteo](https://open-meteo.com/)
* Case 3D printed from [Thingiverse](https://www.thingiverse.com/thing:3996613)
