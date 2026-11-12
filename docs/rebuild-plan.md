# Tank rebuild

## What I want to build

Rebuild my roughly 1 m long RC tank with a stronger frame. Keep the general layout and reuse the motors, electronics, shocks, and suspension arms where they still work. The old printed frame snapped as the whole tank bent. The exact crack locations and failed joints still need documenting.

Use this repo as the project folder. Nothing has been designed or built for the new tank yet. Forge funding comes later, once the design and budget are clearer.

## How I'll use it

These are rough answers from memory, not measurements.

- Weight: the old tank was somewhere between 10 and 20 kg with the battery in. It still needs weighing.
- Terrain: all of it. Indoor floors, grass, rough ground like dirt and gravel, and drops and curbs.
- Payload: nobody sits on the tank itself. The old tank could pull a cart with me sitting in the cart, and the new one should be able to do that too. Where the cart hooked on and how heavy the cart was still need recording.
- Reuse: the new tank keeps the same electronics and motors.
- I don't remember what was happening when the old frame snapped, or whether it got worse over time.

Drops and a heavy payload put the biggest loads on the tank, so the new frame, suspension, rollers, and track pins need to be checked against those, not just against driving on flat ground.

## Tools available

The makerspace has a mitre saw and drill press. I do not own them, and I do not have a welder. Plan around bolted construction. Before choosing stock or a cutting method, check with the makerspace that the saw, blade, workholding, and rules allow the chosen metal.

## What happened on the old tank

- The thick printed pins between the suspension arms and frame kept snapping. I replaced them with aluminium rods of roughly the same diameter, about 15 mm, held by printed clamps tightened with screws. That worked okay. Each rod stayed stationary and carried two arms, one on each side, which rotated independently around it. The diameter is only a rough reference and needs measuring.
- The printed pins between the suspension arms and bottom rollers also snapped. I replaced them with bolts and deliberately made the wheel holes slightly smaller than the bolts so the threads would bite into the plastic. The rollers were completely locked. The moving track rubbed against them and wore their ends quickly. This was wear at the track contact, not a reported failure of a freely rotating wheel's centre hole. The exact dimensions and fastening arrangement still need checking.
- The track links worked well overall, although some printed connecting pins snapped. Keep the links if their condition allows it, and investigate the pin failures separately.
- The wheels and tracks came from someone else's model, possibly on Thingiverse, and were scaled up. I did not design the original parts. The source, licence, and scale factor still need finding.
- The motor connection to the drive wheel used to slip. I modified the drive wheel to use a flange coupler, and that works very well. Keep that connection as the starting point.
- The bottom rollers need redesigning. Scaling up the original mesh made the flat facets around the wheels more noticeable. Make smooth replacement geometry and check how the rollers will rotate on their axles.

These are separate from the main frame bending failure. A stronger frame alone will not resolve the roller rotation or track-pin issues. Reuse the suspension arms where possible, but inspect their pivot holes and condition first.

The replacement bottom rollers need to rotate freely while being retained securely. Preserve independent left and right suspension movement around the stationary rods. Bearing or bushing details, axle retention, and clearances are still undecided. Photos will be added when available; none were available for this description.

## Where the wheels and tracks came from

Found on Nov 12, 2026. The wheels, suspension arms, sprockets, and tracks come from two Thingiverse designs by fastmike75, which I scaled up:

- Tank, Sprockets, Mag Idler Wheels, Suspension Arms: https://www.thingiverse.com/thing:2699624 (CC BY-NC). The mag road wheels with two o-ring grooves (1.5", 1.75", 2" and 2.25" sizes), the suspension arms, idler and drive sprockets, and a track tension arm.
- Tank Track 2in, Track, grousers, sprockets: https://www.thingiverse.com/thing:471357 (CC BY-SA). The track links, grouser bars, and drive sprockets. This one is a remix of "Tank tracks, Flat surface, Heavy-Duty" by night--wolf: https://www.thingiverse.com/thing:163486 (CC BY-SA).

Scale: my rollers are about 105 and 92 across, which matches his 2" and 1.75" wheels at about 2.06 times. My track is about 105 wide, which matches his 2" track at the same scale. So everything was scaled up to roughly 206%. This comes from comparing his listed sizes with my files, not from measuring his original files.

The shock absorber model (susp_noprint) isn't in either listing, so where it came from still needs checking. The drive wheel started as his drive sprocket B from the track set (matched by eye from his picture), and I added a hub for the flange coupler.

Useful notes from his listings:

- He joined the track links with steel wire brad nails (#15 gauge, about 1.8 mm), not printed pins. At 2.06 times that would be about 3.8 mm. That explains why my printed pins snapped. Metal pins are the obvious thing to try for the rebuild.
- His own tank used a frame of 1/8" x 1 1/2" flat aluminium bars with metal angle brackets. That's close to what I want to do, so his frame is worth a look: Fastmike Tank Frame Parts, https://www.thingiverse.com/thing:2827980
- He says track tension is a must but too much adds a lot of drag. He used a spring-loaded tension arm.

Licences:

- Credit fastmike75, and night--wolf for the track, wherever these files are shared.
- The wheel and arm files are non-commercial (BY-NC). Fine for a personal project, but not for selling them or parts made from them. Check Forge's rules on this before applying.
- The track files are share-alike (BY-SA). Changed versions I share have to use CC BY-SA too.
- The MIT licence on this repo doesn't cover these files. The repo needs a note saying which files came from where and under which licence.

How it was found: no credits in the repo or the files, no matching downloads on this Mac, and nothing useful in my Tinkercad account (the "1m long tank" design was created Sep 16, 2024 and has no "copied from" credit). Once I remembered the arms, wheels, and tracks came as a set, a search for tank suspension arm sets turned up fastmike75.

## Electronics and code

There are two different Arduino sketches that are both called tonk_control_v2. Don't flash either one based on the name. Check the motor driver and wiring on the tank first.

- Older, in this repo at `../code/tonk_control_v2/`: left motor on D13/D11, right motor on D12/D3, RC inputs on D5/D6. If the RC signal drops out it may keep running the motors at the last speed.
- Newer, outside this repo at `~/Documents/Arduino/tonk_control_v2/`: left motor on D8/D9, right motor on D13/D11, RC inputs on D5/D6, wheel encoders on D2/D3. Bad RC signals set the motors back to neutral, and it ramps speed changes instead of jumping.

The newer sketch was uploaded to an Uno R3 in June, but what is on the board now, the current wiring, and the encoders have not been checked since.

## Starting layout to investigate

Continuous metal side rails with bolted crossmembers, keeping the existing suspension geometry where practical. Check how the suspension, shocks, motors, and track tension load the frame before choosing rail sections or brackets. Aluminium is the preferred material to investigate; steel is still an option if the requirements call for it. Material, section sizes, fasteners, and mounting details are not selected yet.

## Roadmap

- [x] Find the old GitHub repo and Tinkercad project.
- [x] Download the full Tinkercad design as STL and OBJ.
- [x] Save the reference files in this repo and verify the copies.
- [x] Record the reported failure and available tools.
- [x] Record the suspension-pin replacements, roller wear, track performance, and flange-coupler fix.
- [ ] Photograph the cracks and identify which frame pieces failed.
- [x] Record rough weight, terrain, and payload.
- [ ] Weigh the tank with its battery and decide the heaviest payload it needs to carry.
- [ ] Check the reusable parts and record their mounting dimensions.
- [x] Establish that the old roller bolts gripped undersized holes, locked the rollers, and caused sliding contact with the moving track.
- [ ] Measure the bottom roller axle assembly and track-contact surfaces; agree on axle retention and the rotating interface before redesigning it.
- [x] Find the original wheel and track model, its licence, and the scale factor used.
- [x] Add a credits and licence note for the fastmike75 and night--wolf files to the repo (README, Nov 12, 2026).
- [ ] Find where the shock absorber model came from.
- [ ] Inspect the track pins and decide whether their replacement is needed while keeping the links. The original design used metal brad nails, not printed pins.
- [ ] Measure the assembled frame width, suspension pivots, shock mounts, sprocket and idler positions, and track adjustment.
- [ ] Check metal-cutting options and available stock with the makerspace.
- [ ] Compare frame sections and joint layouts against the loads and clearances.
- [ ] Agree on the layout and dimensions before making new CAD.
- [ ] Redesign the bottom rollers with smooth geometry and the agreed axle arrangement.
- [ ] Design the frame and brackets, then make the BOM and Forge funding plan.
- [ ] Build, inspect, and test in stages.

## Existing design references

- GitHub: https://github.com/EwoudVV/rc-tank
- Tinkercad: https://www.tinkercad.com/things/fil1NRZ0k6M-1m-long-tank
- Current full-design exports: `../design files/reference/2026-10-23/`
- Older individual parts: `../design files/`
- Older layout screenshot: `../images/Screenshot 2025-05-17 at 16.03.34.png`

The dated reference folder contains the original STL download, the original OBJ ZIP, and its extracted OBJ and MTL files. These are mesh references, not parametric CAD or a backup of the editable Tinkercad history.

The older full_side.stl has an oriented bounding box of about 1000 x 60 x 30 model units. This assumes millimetres and needs checking against the built tank. The current whole-workspace STL spans about 894 x 1067 x 192 model units, including loose parts; those are not assembled tank dimensions.

Existing repo changes were left in place. No firmware was flashed, and no commits or uploads were made.
