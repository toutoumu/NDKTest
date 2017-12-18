#include <jni.h>

#include "hevcimagefilereader.hpp"
#include <iostream>

using namespace std;

bool example2(const std::string &fileName) {
    HevcImageFileReader reader;
    ImageFileReaderInterface::DataVector data;
    ImageFileReaderInterface::IdVector itemIds;

    reader.initialize(fileName);
    const auto &properties = reader.getFileProperties();

    // Verify that the file has one or several images in the MetaBox
    if (not(properties.fileFeature.hasFeature(
            ImageFileReaderInterface::FileFeature::HasSingleImage) ||
            properties.fileFeature.hasFeature(
                    ImageFileReaderInterface::FileFeature::HasImageCollection))) {
        return false;
    }

    // Find the item ID of the first master image
    const uint32_t contextId = properties.rootLevelMetaBoxProperties.contextId;
    reader.getItemListByType(contextId, "master", itemIds);
    const uint32_t masterId = itemIds.at(0);

    const auto &metaBoxFeatures = properties.rootLevelMetaBoxProperties.metaBoxFeature; // For convenience
    if (metaBoxFeatures.hasFeature(ImageFileReaderInterface::MetaBoxFeature::HasThumbnails)) {
        // Thumbnail references ('thmb') are from the thumbnail image to the master image
        reader.getReferencedToItemListByType(contextId, masterId, "thmb", itemIds);
        if (itemIds.size() > 0) {
            const uint32_t thumbnailId = itemIds.at(0);

            reader.getItemDataWithDecoderParameters(contextId, thumbnailId, data);
        } else {
            // There was no thumbnail, show just the master image
            reader.getItemDataWithDecoderParameters(contextId, masterId, data);
            // ...decode and display...
            std::fstream file("/storage/emulated/0/Download/map.jpg", std::ios::binary);
            //for (size_t n = 0; n < data.size(); n++) {
                // data[n] = 40;
            //}
            file.write(reinterpret_cast<char *>(&data[0]), data.size() * sizeof(data[0]));
            file.flush();
            file.close();
        }
        // ...decode data and display the image, show master image later
    } else {
        // There was no thumbnail, show just the master image
        reader.getItemDataWithDecoderParameters(contextId, masterId, data);
        // ...decode and display...
    }
    return true;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_heif_HEIFUtils_redHEIF(JNIEnv *env, jobject instance, jstring fileName_) {
    const char *fileName = env->GetStringUTFChars(fileName_, 0);

    if (example2(fileName)) {
        env->ReleaseStringUTFChars(fileName_, fileName);

        std::string hello = "Hello from C++";
        return env->NewStringUTF(hello.c_str());
    }
    env->ReleaseStringUTFChars(fileName_, fileName);

    return env->NewStringUTF(fileName);
}