/*
 * Copyright 2012-2014 Moritz Hilscher
 *
 * This file is part of Mapcrafter.
 *
 * Mapcrafter is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Mapcrafter is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Mapcrafter.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MAPCRAFTERCONFIGHELPER_H_
#define MAPCRAFTERCONFIGHELPER_H_

#include "mapcrafterconfig.h"
#include "../renderer/tileset.h"

#include <array>
#include <map>
#include <set>
#include <vector>

namespace mapcrafter {
namespace config {

class MapcrafterConfigHelper {
private:
	MapcrafterConfig config;

	std::map<std::string, std::set<int> > world_rotations;
	std::map<std::string, int> map_tile_sizes, world_zoomlevels, map_zoomlevels;
	std::map<std::string, std::array<renderer::TilePos, 4> > world_tile_offsets;

	std::map<std::string, std::array<int, 4> > render_behaviors;

	void setRenderBehaviors(std::vector<std::string> maps, int behavior);
public:
	MapcrafterConfigHelper();
	MapcrafterConfigHelper(const MapcrafterConfig& config);
	~MapcrafterConfigHelper();

	std::string generateTemplateJavascript() const;

	const std::set<int>& getUsedRotations(const std::string& world) const;
	void setUsedRotations(const std::string& world, const std::set<int>& rotations);

	int getMapTileSize(const std::string& map) const;
	void setMapTileSize(const std::string& map, int tile_size);

	int getWorldZoomlevel(const std::string& world) const;
	int getMapZoomlevel(const std::string& map) const;
	void setWorldZoomlevel(const std::string& world, int zoomlevel);
	void setMapZoomlevel(const std::string& map, int zoomlevel);

	void setWorldTileOffset(const std::string& world, int rotation,
			const renderer::TilePos& tile_offset);
	const renderer::TilePos& getWorldTileOffset(const std::string& world, int rotation);

	int getRenderBehavior(const std::string& map, int rotation) const;
	void setRenderBehavior(const std::string& map, int rotation, int behavior);

	bool isCompleteRenderSkip(const std::string& map) const;
	bool isCompleteRenderForce(const std::string& map) const;

	void parseRenderBehaviors(bool skip_all,
			std::vector<std::string>,
			std::vector<std::string> render_auto,
			std::vector<std::string> render_force);

	static const int RENDER_SKIP = 0;
	static const int RENDER_AUTO = 1;
	static const int RENDER_FORCE = 2;
};

} /* namespace config */
} /* namespace mapcrafter */

#endif /* MAPCRAFTERCONFIGHELPER_H_ */
