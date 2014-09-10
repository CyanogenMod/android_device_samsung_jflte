/*
 * Copyright (C) 2013 Xiao-Long Chen <chenxiaolong@cxl.epac.to>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package org.cyanogenmod.hardware;

import org.cyanogenmod.hardware.util.FileUtils;
import java.io.File;

/**
 * Glove mode / high touch sensitivity (on Samsung Galaxy S4)
 */
public class HighTouchSensitivity {
    private static String COMMAND_PATH = "/sys/class/sec/tsp/cmd";
    private static String RESULT_PATH = "/sys/class/sec/tsp/cmd_result";
    private static String GLOVE_MODE_ENABLE = "glove_mode,1";
    private static String GLOVE_MODE_DISABLE = "glove_mode,0";
    private static String STATUS_OK = ":OK";

    /**
     * Whether device supports high touch sensitivity.
     *
     * @return boolean Supported devices must return always true
     */
    public static boolean isSupported() {
        File f = new File(COMMAND_PATH);
        return f.exists();
    }

    /** This method returns the current activation status of high touch sensitivity
     *
     * @return boolean Must be false if high touch sensitivity is not supported or not activated,
     * or the operation failed while reading the status; true in any other case.
     */
    public static boolean isEnabled() {
        return FileUtils.readOneLine(RESULT_PATH).equals(GLOVE_MODE_ENABLE + STATUS_OK);
    }

    /**
     * This method allows to setup high touch sensitivity status.
     *
     * @param status The new high touch sensitivity status
     * @return boolean Must be false if high touch sensitivity is not supported or the operation
     * failed; true in any other case.
     */
    public static boolean setEnabled(boolean status) {
        return FileUtils.writeLine(COMMAND_PATH, (status ? GLOVE_MODE_ENABLE : GLOVE_MODE_DISABLE));
    }
}
