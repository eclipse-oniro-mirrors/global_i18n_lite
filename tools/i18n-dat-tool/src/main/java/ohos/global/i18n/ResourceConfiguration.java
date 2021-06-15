package ohos.global.i18n;

import java.io.File;
import java.io.IOException;
import java.net.URISyntaxException;
import java.util.Iterator;
import java.util.ArrayList;
import org.codehaus.jackson.map.ObjectMapper;
import org.codehaus.jackson.JsonNode;
import org.codehaus.jackson.annotate.JsonIgnoreProperties;


public class ResourceConfiguration {
    private ResourceConfiguration() {}

    public static ArrayList<ResourceConfiguration.ConfigItem> parse() {
        ArrayList<ResourceConfiguration.ConfigItem> ret = new ArrayList<>();
        try {
            File json = new File(ResourceConfiguration.class.getResource("/resource/resource_items.json").toURI());
            ObjectMapper mapper = new ObjectMapper();
            JsonNode jsonNode = mapper.readTree(json);
            Iterator<JsonNode> jsonNodes = jsonNode.getElements();
            int count = 0;
            while (jsonNodes.hasNext()) {
                JsonNode node = jsonNodes.next();
                ConfigItem item = mapper.treeToValue(node, ConfigItem.class);
                if (count != item.index) {
                    throw new IllegalStateException("not consecutive index for index " + count);
                }
                ++count;
                ret.add(item);
            }
        } catch (IOException e) {
            e.printStackTrace();
        } catch (URISyntaxException e) {
            e.printStackTrace();
        }
        return ret;
    }

    @JsonIgnoreProperties(ignoreUnknown = true)
    public static class ConfigItem {
        int index;
        String method;
        public String pub;
        int lengths;
        int offsets;
        public String sep;
        public String pointer;
        public String type;
        public Element[] elements;

        public int getIndex() {
            return index;
        }
        
        public String getMethod() {
            return method;
        }

        public int getLengths() {
            return lengths;
        }

        public int getOffsets() {
            return offsets;
        }

        public String getSep() {
            return sep;
        }
    }

    public static class Element {
        public String AvailableFormat;
        public String skeleton;
        public int enumIndex;
        public int index;
    }

    public static void main(String[] args) {
        ResourceConfiguration.parse();
    }
}
