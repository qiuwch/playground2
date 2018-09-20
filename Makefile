clean:
	rm -rf Intermediate/ Saved/ Binaries/ *.sln Plugins/unrealcv/Intermediate/ Plugins/unrealcv/Binaries/

zip:
	zip -r Playground.zip Playground.uproject Source Plugins Config playground.md
